# ReasonML experiment

[![Build Status](https://travis-ci.org/cjdelisle/reasonml-experiment.svg?branch=master)](https://travis-ci.org/cjdelisle/reasonml-experiment)

To make this thing work:

```bash
$ brew install opam # if on OSX
$ opam init
$ opam switch 4.02.3+buckle-master
$ eval `opam config env`
$ opam install ocamlfind lwt uwt reason
$ npm install
$ npm run build
$ ./lib/bs/native/test.native
```

## Conclusions

* It's small and supposedly fast
  * 1.5MB stripped executable on a mac (embedding libuv)
  * Hello world is 100k
* It's not JS, there *is* a learning curve
  * It's not immediately obvious when a function is being defined
  * Syntax extensions add new operators which do special things, these remain popular in OCaml world
  * You probably end up learning OCaml in order to read the examples from libraries you want to use
* It's a super powerful language
  * Syntax extensions
  