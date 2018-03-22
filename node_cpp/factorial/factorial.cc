#include <node.h>

namespace factorial {

using v8::FunctionCallbackInfo;
using v8::Exception;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Number;
using v8::Value;

void findFactorial(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  if(args.Length() != 1) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong number of arguments")));
    return;
  }

  if (!args[0]->IsNumber()) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong arguments")));
    return;
  }

  int rawNumber=args[0]->NumberValue();
  long int fact=1;
  while(rawNumber > 0) {
    fact = fact * rawNumber;
    rawNumber--;
  }

  args.GetReturnValue().Set(Number::New(isolate, fact));
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "find", findFactorial);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, init)

}
