#include <node.h>

namespace sum_perfomance {

using v8::FunctionCallbackInfo;
using v8::Exception;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Number;
using v8::Value;

void findSumPerfomance(const FunctionCallbackInfo<Value>& args) {
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

  long int totalSum = 0;
  int rawNumber=args[0]->NumberValue();

  while(rawNumber > 0){
    totalSum += 1;
    rawNumber--;
  }

  args.GetReturnValue().Set(Number::New(isolate, totalSum));
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "sumNow", findSumPerfomance);
}

NODE_MODULE(sum_perfomance, init)

}
