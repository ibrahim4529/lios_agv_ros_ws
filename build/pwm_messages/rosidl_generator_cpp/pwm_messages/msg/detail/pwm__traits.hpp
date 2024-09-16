// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pwm_messages:msg/Pwm.idl
// generated code does not contain a copyright notice

#ifndef PWM_MESSAGES__MSG__DETAIL__PWM__TRAITS_HPP_
#define PWM_MESSAGES__MSG__DETAIL__PWM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pwm_messages/msg/detail/pwm__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace pwm_messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const Pwm & msg,
  std::ostream & out)
{
  out << "{";
  // member: pwm1
  {
    out << "pwm1: ";
    rosidl_generator_traits::value_to_yaml(msg.pwm1, out);
    out << ", ";
  }

  // member: pwm2
  {
    out << "pwm2: ";
    rosidl_generator_traits::value_to_yaml(msg.pwm2, out);
    out << ", ";
  }

  // member: pwm3
  {
    out << "pwm3: ";
    rosidl_generator_traits::value_to_yaml(msg.pwm3, out);
    out << ", ";
  }

  // member: pwm4
  {
    out << "pwm4: ";
    rosidl_generator_traits::value_to_yaml(msg.pwm4, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Pwm & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pwm1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pwm1: ";
    rosidl_generator_traits::value_to_yaml(msg.pwm1, out);
    out << "\n";
  }

  // member: pwm2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pwm2: ";
    rosidl_generator_traits::value_to_yaml(msg.pwm2, out);
    out << "\n";
  }

  // member: pwm3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pwm3: ";
    rosidl_generator_traits::value_to_yaml(msg.pwm3, out);
    out << "\n";
  }

  // member: pwm4
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pwm4: ";
    rosidl_generator_traits::value_to_yaml(msg.pwm4, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Pwm & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace pwm_messages

namespace rosidl_generator_traits
{

[[deprecated("use pwm_messages::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const pwm_messages::msg::Pwm & msg,
  std::ostream & out, size_t indentation = 0)
{
  pwm_messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pwm_messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const pwm_messages::msg::Pwm & msg)
{
  return pwm_messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pwm_messages::msg::Pwm>()
{
  return "pwm_messages::msg::Pwm";
}

template<>
inline const char * name<pwm_messages::msg::Pwm>()
{
  return "pwm_messages/msg/Pwm";
}

template<>
struct has_fixed_size<pwm_messages::msg::Pwm>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<pwm_messages::msg::Pwm>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<pwm_messages::msg::Pwm>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PWM_MESSAGES__MSG__DETAIL__PWM__TRAITS_HPP_
