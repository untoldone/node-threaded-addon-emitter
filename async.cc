#include <nan.h>

#include "generator.h"

using Nan::Callback;
using Nan::GetFunction;
using Nan::HandleScope;
using Nan::New;
using Nan::Set;
using v8::Function;
using v8::FunctionTemplate;
using v8::Number;
using v8::String;

GeneratorContext *context;

// DEMO THREAD
pthread_t tid[2];

struct hello_args {
  int first;
};

Local<Array> hello_parser(void *generic) {
  hello_args *args = static_cast<hello_args *>(generic);
  Local<Array> argv = New<Array>();
  argv->Set(0, New<Number>(args->first));

  delete args;

  return argv;
}

const struct GeneratorType MY_FIRST_TYPE {
  .name = "hello",
  .arg_parser = hello_parser
};

void* doSomeThing(void *arg)
{
  unsigned long i = 0;

  hello_args *args = new hello_args;
  args->first = 14;
  generator_emit(context, &MY_FIRST_TYPE, args);

  for(i=0; i<(0xFFFFFFFF);i++);

  return NULL;
}

void delay()
{
  int i = 0;
  int err;

  err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
  if (err != 0)
    printf("\ncan't create thread :[%s]", strerror(err));
}

// END DEMO THREAD

NAN_METHOD(NativeEmitter) {
  HandleScope scope;

  context = new GeneratorContext;
  context->callback = new Callback(info[0].As<Function>());

  delay();
}

NAN_MODULE_INIT(InitAll) {
  Set(target, New<String>("nativeEmitter").ToLocalChecked(),
    GetFunction(New<FunctionTemplate>(NativeEmitter)).ToLocalChecked());
}

NODE_MODULE(addon, InitAll)