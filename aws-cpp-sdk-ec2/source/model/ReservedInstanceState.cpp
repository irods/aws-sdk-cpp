/*
* Copyright 2010-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/
#include <aws/ec2/model/ReservedInstanceState.h>
#include <aws/core/utils/HashingUtils.h>

using namespace Aws::Utils;

static const int payment_pending_HASH = HashingUtils::HashString("payment-pending");
static const int active_HASH = HashingUtils::HashString("active");
static const int payment_failed_HASH = HashingUtils::HashString("payment-failed");
static const int retired_HASH = HashingUtils::HashString("retired");

namespace Aws
{
namespace EC2
{
namespace Model
{
namespace ReservedInstanceStateMapper
{
ReservedInstanceState GetReservedInstanceStateForName(const Aws::String& name)
{
  int hashCode = HashingUtils::HashString(name.c_str());

  if (hashCode == payment_pending_HASH)
  {
    return ReservedInstanceState::payment_pending;
  }
  else if (hashCode == active_HASH)
  {
    return ReservedInstanceState::active;
  }
  else if (hashCode == payment_failed_HASH)
  {
    return ReservedInstanceState::payment_failed;
  }
  else if (hashCode == retired_HASH)
  {
    return ReservedInstanceState::retired;
  }

  return ReservedInstanceState::NOT_SET;
}

Aws::String GetNameForReservedInstanceState(ReservedInstanceState value)
{
  switch(value)
  {
  case ReservedInstanceState::payment_pending:
    return "payment-pending";
  case ReservedInstanceState::active:
    return "active";
  case ReservedInstanceState::payment_failed:
    return "payment-failed";
  case ReservedInstanceState::retired:
    return "retired";
  default:
    return "";
  }
}

} // namespace ReservedInstanceStateMapper
} // namespace Model
} // namespace EC2
} // namespace Aws