#include <ATen/PythonTorchFunctionTLS.h>
#include <c10/core/TensorImpl.h>

namespace at {
namespace impl {

static thread_local PythonTorchFunctionTLS pythonTorchFunctionState;

void PythonTorchFunctionTLS::set_mode(std::shared_ptr<c10::SafePyObject> mode) {
  pythonTorchFunctionState.mode_ = std::move(mode);
}

const std::shared_ptr<c10::SafePyObject>& PythonTorchFunctionTLS::get_mode() {
  return pythonTorchFunctionState.mode_;
}

void PythonTorchFunctionTLS::swap_mode(std::shared_ptr<c10::SafePyObject>& mode) {
  pythonTorchFunctionState.mode_.swap(mode);
}

void PythonTorchFunctionTLS::push_onto_stack(std::shared_ptr<SafePyObject> mode) {
  pythonTorchFunctionState.stack_.push_back(std::move(mode));
}

const std::shared_ptr<SafePyObject>& PythonTorchFunctionTLS::pop_stack() {
  TORCH_CHECK(pythonTorchFunctionState.stack_.size() > 0, "trying to pop from empty mode stack");
  const auto out = pythonTorchFunctionState.stack_.back();
  pythonTorchFunctionState.stack_.pop_back();
  return std::move(out);
}

const std::shared_ptr<SafePyObject>& PythonTorchFunctionTLS::get_stack_at(int64_t idx) {
  TORCH_CHECK(idx < static_cast<int64_t>(pythonTorchFunctionState.stack_.size()), "Tried to get stack at idx that's too big");
  return pythonTorchFunctionState.stack_[idx];
}

int64_t PythonTorchFunctionTLS::stack_len() {
  return pythonTorchFunctionState.stack_.size();
}

void PythonTorchFunctionTLS::set_disabled(bool disabled) {
  pythonTorchFunctionState.disabled_ = disabled;
}

bool PythonTorchFunctionTLS::is_disabled() {
  return pythonTorchFunctionState.disabled_;
}

void PythonTorchFunctionTLS::set_state(const PythonTorchFunctionTLS& state) {
  pythonTorchFunctionState = state;
}

const PythonTorchFunctionTLS& PythonTorchFunctionTLS::get_state() {
  return pythonTorchFunctionState;
}

} // namespace impl
} // namespace at
