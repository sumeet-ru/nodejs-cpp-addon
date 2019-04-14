// loop_addon.cc
#include <node.h>

namespace loop_addon {

using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::String;
using v8::Value;

void loopPerformance(const FunctionCallbackInfo<Value> &args) {
    Isolate *isolate = args.GetIsolate();
    long int totalSum = 0;
    int rawNumber = args[0]->NumberValue();  // Get function call arguments.

    while (rawNumber > 0) {
        totalSum += 1;
        rawNumber--;
    }

    args.GetReturnValue().Set(Number::New(isolate, totalSum)); // Send response to JavaScript
}

void init(Local<Object> exports) {
    NODE_SET_METHOD(exports, "sumNow", loopPerformance);
}

NODE_MODULE(loop_addon, init)
}