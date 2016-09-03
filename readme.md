Usage Instructions
==================

To see this example functioning run:

    npm install
    node demo.js

The files are as follows:

* generator.cc: Where we safely build emitter results on the event loop
* async.cc: entry point for the addon, where the secondary thread is created, plus a sample type to be emitted
* index.js: addon javascript interface to c code
* demo.js: example usage of addon
