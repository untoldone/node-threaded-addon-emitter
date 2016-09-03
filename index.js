var learn = require('./build/release/node-async-learn');

const EventEmitter = require('events');

class MyEmitter extends EventEmitter {
  constructor() {
    super();
    this._generator = learn.nativeEmitter(this._handler.bind(this));
  }

  _handler(event, args) {
    args.unshift(event);
    this.emit.apply(this, args);
  }
}

module.exports = MyEmitter;
