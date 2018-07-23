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

## Observations

* It's small and supposedly fast
  * 1.5MB stripped executable on a mac (embedding libuv)
  * Hello world is 100k
* It's not JS, there *is* a learning curve
  * It's not immediately obvious when a function is being defined
  * Syntax extensions add new operators which do special things, these remain popular in OCaml world
  * You probably end up learning OCaml in order to read the examples from libraries you want to use
* It's a super powerful language
  * Syntax extensions / macros
    * ppx compile time execution, code generation
  * Type inference - types never get in the way
  * Exceptions
* Good tools & ecosystem
  * Debugging
  * Build tools
  * libraries
* Opam is like python, global
* Compiles to javascript but not to WASM
  * No significant performance gain over well written JS
* Single threaded - can have threads but uses a GIL
* ReasonML is not designed for native builds, it's designed to be a TypeScript competitor
  * Not (yet?) a serious nodejs replacement
* ReasomML build scripts leave something to be desired
  * Bucklescript-native
    * Builder we're using here, requires switching to specific version of ocaml to use
  * esy - couldn't get this to work
    * `esy init` does not make a fresh package.json
    * Attempts to do a virtual-env, and so it compiles ocaml which takes a few minutes
  * Using vscode, merlin created too many processes, got resource limit errors, had to killall

  