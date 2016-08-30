﻿/*
* Copyright 2010-2016 Amazon.com, Inc. or its affiliates. All Rights Reserved.
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
#include <aws/codepipeline/model/ArtifactRevisionInformation.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace CodePipeline
{
namespace Model
{

ArtifactRevisionInformation::ArtifactRevisionInformation() : 
    m_nameHasBeenSet(false),
    m_revisionHasBeenSet(false)
{
}

ArtifactRevisionInformation::ArtifactRevisionInformation(const JsonValue& jsonValue) : 
    m_nameHasBeenSet(false),
    m_revisionHasBeenSet(false)
{
  *this = jsonValue;
}

ArtifactRevisionInformation& ArtifactRevisionInformation::operator =(const JsonValue& jsonValue)
{
  if(jsonValue.ValueExists("name"))
  {
    m_name = jsonValue.GetString("name");

    m_nameHasBeenSet = true;
  }

  if(jsonValue.ValueExists("revision"))
  {
    m_revision = jsonValue.GetObject("revision");

    m_revisionHasBeenSet = true;
  }

  return *this;
}

JsonValue ArtifactRevisionInformation::Jsonize() const
{
  JsonValue payload;

  if(m_nameHasBeenSet)
  {
   payload.WithString("name", m_name);

  }

  if(m_revisionHasBeenSet)
  {
   payload.WithObject("revision", m_revision.Jsonize());

  }

  return payload;
}

} // namespace Model
} // namespace CodePipeline
} // namespace Aws