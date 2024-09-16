// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pwm_messages:msg/Pwm.idl
// generated code does not contain a copyright notice

#ifndef PWM_MESSAGES__MSG__DETAIL__PWM__STRUCT_HPP_
#define PWM_MESSAGES__MSG__DETAIL__PWM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__pwm_messages__msg__Pwm __attribute__((deprecated))
#else
# define DEPRECATED__pwm_messages__msg__Pwm __declspec(deprecated)
#endif

namespace pwm_messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Pwm_
{
  using Type = Pwm_<ContainerAllocator>;

  explicit Pwm_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pwm1 = 0l;
      this->pwm2 = 0l;
      this->pwm3 = 0l;
      this->pwm4 = 0l;
    }
  }

  explicit Pwm_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pwm1 = 0l;
      this->pwm2 = 0l;
      this->pwm3 = 0l;
      this->pwm4 = 0l;
    }
  }

  // field types and members
  using _pwm1_type =
    int32_t;
  _pwm1_type pwm1;
  using _pwm2_type =
    int32_t;
  _pwm2_type pwm2;
  using _pwm3_type =
    int32_t;
  _pwm3_type pwm3;
  using _pwm4_type =
    int32_t;
  _pwm4_type pwm4;

  // setters for named parameter idiom
  Type & set__pwm1(
    const int32_t & _arg)
  {
    this->pwm1 = _arg;
    return *this;
  }
  Type & set__pwm2(
    const int32_t & _arg)
  {
    this->pwm2 = _arg;
    return *this;
  }
  Type & set__pwm3(
    const int32_t & _arg)
  {
    this->pwm3 = _arg;
    return *this;
  }
  Type & set__pwm4(
    const int32_t & _arg)
  {
    this->pwm4 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pwm_messages::msg::Pwm_<ContainerAllocator> *;
  using ConstRawPtr =
    const pwm_messages::msg::Pwm_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pwm_messages::msg::Pwm_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pwm_messages::msg::Pwm_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pwm_messages::msg::Pwm_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pwm_messages::msg::Pwm_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pwm_messages::msg::Pwm_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pwm_messages::msg::Pwm_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pwm_messages::msg::Pwm_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pwm_messages::msg::Pwm_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pwm_messages__msg__Pwm
    std::shared_ptr<pwm_messages::msg::Pwm_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pwm_messages__msg__Pwm
    std::shared_ptr<pwm_messages::msg::Pwm_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Pwm_ & other) const
  {
    if (this->pwm1 != other.pwm1) {
      return false;
    }
    if (this->pwm2 != other.pwm2) {
      return false;
    }
    if (this->pwm3 != other.pwm3) {
      return false;
    }
    if (this->pwm4 != other.pwm4) {
      return false;
    }
    return true;
  }
  bool operator!=(const Pwm_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Pwm_

// alias to use template instance with default allocator
using Pwm =
  pwm_messages::msg::Pwm_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pwm_messages

#endif  // PWM_MESSAGES__MSG__DETAIL__PWM__STRUCT_HPP_
