let server_port = 9009;
module Udp = Uwt.Udp;

let log = s => ignore(Uwt_io.eprintl(s));

let wait = () => {
  let signals = [Sys.sigint, Sys.sigterm];
  let (sleeper, waker) = Lwt.task();
  let wake_once = lazy (Lwt.wakeup(waker, ()));
  let cb = (_sig, _i) => Lazy.force(wake_once);
  let l = List.map(s => Uwt.Signal.start_exn(s, ~cb), signals);
  let close_all = () => {
    List.iter(Uwt.Signal.close_noerr, l);
    Lwt.return_unit;
  };
  Lwt.finalize(() => Lwt.pick([sleeper]), () => close_all());
};

let start_server = () => {
  let server = Udp.init();
  let cb =
    fun
    | Udp.Data(_, None) => log("data, but no address")
    | Udp.Partial_data(_, None) => log("partial data, but no address")
    | Udp.Empty_from(_) => log("empty datagram")
    | Udp.Transmission_error(_) => log("transmission error")
    | Udp.Data(b, Some(x))
    | Udp.Partial_data(b, Some(x)) => ignore(Udp.send(server, ~buf=b, x));

  Lwt.finalize(
    () => {
      let addr = Uwt.Misc.ip4_addr_exn("127.0.0.1", server_port);
      let () = Udp.bind_exn(~mode=[Udp.Reuse_addr], server, ~addr, ());
      let () = Udp.recv_start_exn(server, ~cb);

      print_endline("bound to port " ++ string_of_int(server_port));
      print_endline("In another window, try: nc -u 127.0.0.1 " ++ string_of_int(server_port));
      print_endline("and begin typing");

      wait();
    },
    () => {
      Udp.close_noerr(server);
      Lwt.return_unit;
    },
  );
};


let () = Uwt.Main.run(start_server());
