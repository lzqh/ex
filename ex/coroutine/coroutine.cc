#include "coroutine/coroutine.h"

namespace ex{
namespace coroutine{

Coroutine::Coroutine(const Func& func):func_(func) {}
Coroutine::~Coroutine() {}

}
}
