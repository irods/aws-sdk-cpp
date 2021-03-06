﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
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

#include <aws/clouddirectory/model/UpdateLinkAttributesRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::CloudDirectory::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

UpdateLinkAttributesRequest::UpdateLinkAttributesRequest() : 
    m_directoryArnHasBeenSet(false),
    m_typedLinkSpecifierHasBeenSet(false),
    m_attributeUpdatesHasBeenSet(false)
{
}

Aws::String UpdateLinkAttributesRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_typedLinkSpecifierHasBeenSet)
  {
   payload.WithObject("TypedLinkSpecifier", m_typedLinkSpecifier.Jsonize());

  }

  if(m_attributeUpdatesHasBeenSet)
  {
   Array<JsonValue> attributeUpdatesJsonList(m_attributeUpdates.size());
   for(unsigned attributeUpdatesIndex = 0; attributeUpdatesIndex < attributeUpdatesJsonList.GetLength(); ++attributeUpdatesIndex)
   {
     attributeUpdatesJsonList[attributeUpdatesIndex].AsObject(m_attributeUpdates[attributeUpdatesIndex].Jsonize());
   }
   payload.WithArray("AttributeUpdates", std::move(attributeUpdatesJsonList));

  }

  return payload.WriteReadable();
}

Aws::Http::HeaderValueCollection UpdateLinkAttributesRequest::GetRequestSpecificHeaders() const
{
  Aws::Http::HeaderValueCollection headers;
  Aws::StringStream ss;
  if(m_directoryArnHasBeenSet)
  {
    ss << m_directoryArn;
    headers.insert(Aws::Http::HeaderValuePair("x-amz-data-partition", ss.str()));
    ss.str("");
  }

  return headers;

}




