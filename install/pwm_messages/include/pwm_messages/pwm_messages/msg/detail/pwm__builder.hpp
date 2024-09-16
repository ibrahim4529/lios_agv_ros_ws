// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pwm_messages:msg/Pwm.idl
// generated code does not contain a copyright notice

#ifndef PWM_MESSAGES__MSG__DETAIL__PWM__BUILDER_HPP_
#define PWM_MESSAGES__MSG__DETAIL__PWM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pwm_messages/msg/detail/pwm__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pwm_messages
{

namespace msg
{

namespace builder
{

class Init_Pwm_pwm4
{
public:
  explicit Init_Pwm_pwm4(::pwm_messages::msg::Pwm & msg)
  : msg_(msg)
  {}
  ::pwm_messages::msg::Pwm pwm4(::pwm_messages::msg::Pwm::_pwm4_type arg)
  {
    msg_.pwm4 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pwm_messages::msg::Pwm msg_;
};

class Init_Pwm_pwm3
{
public:
  explicit Init_Pwm_pwm3(::pwm_messages::msg::Pwm & msg)
  : msg_(msg)
  {}
  Init_Pwm_pwm4 pwm3(::pwm_messages::msg::Pwm::_pwm3_type arg)
  {
    msg_.pwm3 = std::move(arg);
    return Init_Pwm_pwm4(msg_);
  }

private:
  ::pwm_messages::msg::Pwm msg_;
};

class Init_Pwm_pwm2
{
public:
  explicit Init_Pwm_pwm2(::pwm_messages::msg::Pwm & msg)
  : msg_(msg)
  {}
  Init_Pwm_pwm3 pwm2(::pwm_messages::msg::Pwm::_pwm2_type arg)
  {
    msg_.pwm2 = std::move(arg);
    return Init_Pwm_pwm3(msg_);
  }

private:
  ::pwm_messages::msg::Pwm msg_;
};

class Init_Pwm_pwm1
{
public:
  Init_Pwm_pwm1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Pwm_pwm2 pwm1(::pwm_messages::msg::Pwm::_pwm1_type arg)
  {
    msg_.pwm1 = std::move(arg);
    return Init_Pwm_pwm2(msg_);
  }

private:
  ::pwm_messages::msg::Pwm msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pwm_messages::msg::Pwm>()
{
  return pwm_messages::msg::builder::Init_Pwm_pwm1();
}

}  // namespace pwm_messages

#endif  // PWM_MESSAGES__MSG__DETAIL__PWM__BUILDER_HPP_
