// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from pwm_messages:msg/Pwm.idl
// generated code does not contain a copyright notice

#ifndef PWM_MESSAGES__MSG__DETAIL__PWM__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define PWM_MESSAGES__MSG__DETAIL__PWM__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "pwm_messages/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "pwm_messages/msg/detail/pwm__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace pwm_messages
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pwm_messages
cdr_serialize(
  const pwm_messages::msg::Pwm & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pwm_messages
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  pwm_messages::msg::Pwm & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pwm_messages
get_serialized_size(
  const pwm_messages::msg::Pwm & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pwm_messages
max_serialized_size_Pwm(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace pwm_messages

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pwm_messages
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, pwm_messages, msg, Pwm)();

#ifdef __cplusplus
}
#endif

#endif  // PWM_MESSAGES__MSG__DETAIL__PWM__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
