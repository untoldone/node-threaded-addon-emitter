var h = require('./index');

var y = new h();

y.on('hello', function (h) {
  console.log('got it');
  console.log(h);
});

setTimeout(function () {}, 2000);