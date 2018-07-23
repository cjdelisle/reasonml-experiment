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