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

#include <aws/glue/model/Table.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace Glue
{
namespace Model
{

Table::Table() : 
    m_nameHasBeenSet(false),
    m_databaseNameHasBeenSet(false),
    m_descriptionHasBeenSet(false),
    m_ownerHasBeenSet(false),
    m_createTimeHasBeenSet(false),
    m_updateTimeHasBeenSet(false),
    m_lastAccessTimeHasBeenSet(false),
    m_lastAnalyzedTimeHasBeenSet(false),
    m_retention(0),
    m_retentionHasBeenSet(false),
    m_storageDescriptorHasBeenSet(false),
    m_partitionKeysHasBeenSet(false),
    m_viewOriginalTextHasBeenSet(false),
    m_viewExpandedTextHasBeenSet(false),
    m_tableTypeHasBeenSet(false),
    m_parametersHasBeenSet(false),
    m_createdByHasBeenSet(false)
{
}

Table::Table(const JsonValue& jsonValue) : 
    m_nameHasBeenSet(false),
    m_databaseNameHasBeenSet(false),
    m_descriptionHasBeenSet(false),
    m_ownerHasBeenSet(false),
    m_createTimeHasBeenSet(false),
    m_updateTimeHasBeenSet(false),
    m_lastAccessTimeHasBeenSet(false),
    m_lastAnalyzedTimeHasBeenSet(false),
    m_retention(0),
    m_retentionHasBeenSet(false),
    m_storageDescriptorHasBeenSet(false),
    m_partitionKeysHasBeenSet(false),
    m_viewOriginalTextHasBeenSet(false),
    m_viewExpandedTextHasBeenSet(false),
    m_tableTypeHasBeenSet(false),
    m_parametersHasBeenSet(false),
    m_createdByHasBeenSet(false)
{
  *this = jsonValue;
}

Table& Table::operator =(const JsonValue& jsonValue)
{
  if(jsonValue.ValueExists("Name"))
  {
    m_name = jsonValue.GetString("Name");

    m_nameHasBeenSet = true;
  }

  if(jsonValue.ValueExists("DatabaseName"))
  {
    m_databaseName = jsonValue.GetString("DatabaseName");

    m_databaseNameHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Description"))
  {
    m_description = jsonValue.GetString("Description");

    m_descriptionHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Owner"))
  {
    m_owner = jsonValue.GetString("Owner");

    m_ownerHasBeenSet = true;
  }

  if(jsonValue.ValueExists("CreateTime"))
  {
    m_createTime = jsonValue.GetDouble("CreateTime");

    m_createTimeHasBeenSet = true;
  }

  if(jsonValue.ValueExists("UpdateTime"))
  {
    m_updateTime = jsonValue.GetDouble("UpdateTime");

    m_updateTimeHasBeenSet = true;
  }

  if(jsonValue.ValueExists("LastAccessTime"))
  {
    m_lastAccessTime = jsonValue.GetDouble("LastAccessTime");

    m_lastAccessTimeHasBeenSet = true;
  }

  if(jsonValue.ValueExists("LastAnalyzedTime"))
  {
    m_lastAnalyzedTime = jsonValue.GetDouble("LastAnalyzedTime");

    m_lastAnalyzedTimeHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Retention"))
  {
    m_retention = jsonValue.GetInteger("Retention");

    m_retentionHasBeenSet = true;
  }

  if(jsonValue.ValueExists("StorageDescriptor"))
  {
    m_storageDescriptor = jsonValue.GetObject("StorageDescriptor");

    m_storageDescriptorHasBeenSet = true;
  }

  if(jsonValue.ValueExists("PartitionKeys"))
  {
    Array<JsonValue> partitionKeysJsonList = jsonValue.GetArray("PartitionKeys");
    for(unsigned partitionKeysIndex = 0; partitionKeysIndex < partitionKeysJsonList.GetLength(); ++partitionKeysIndex)
    {
      m_partitionKeys.push_back(partitionKeysJsonList[partitionKeysIndex].AsObject());
    }
    m_partitionKeysHasBeenSet = true;
  }

  if(jsonValue.ValueExists("ViewOriginalText"))
  {
    m_viewOriginalText = jsonValue.GetString("ViewOriginalText");

    m_viewOriginalTextHasBeenSet = true;
  }

  if(jsonValue.ValueExists("ViewExpandedText"))
  {
    m_viewExpandedText = jsonValue.GetString("ViewExpandedText");

    m_viewExpandedTextHasBeenSet = true;
  }

  if(jsonValue.ValueExists("TableType"))
  {
    m_tableType = jsonValue.GetString("TableType");

    m_tableTypeHasBeenSet = true;
  }

  if(jsonValue.ValueExists("Parameters"))
  {
    Aws::Map<Aws::String, JsonValue> parametersJsonMap = jsonValue.GetObject("Parameters").GetAllObjects();
    for(auto& parametersItem : parametersJsonMap)
    {
      m_parameters[parametersItem.first] = parametersItem.second.AsString();
    }
    m_parametersHasBeenSet = true;
  }

  if(jsonValue.ValueExists("CreatedBy"))
  {
    m_createdBy = jsonValue.GetString("CreatedBy");

    m_createdByHasBeenSet = true;
  }

  return *this;
}

JsonValue Table::Jsonize() const
{
  JsonValue payload;

  if(m_nameHasBeenSet)
  {
   payload.WithString("Name", m_name);

  }

  if(m_databaseNameHasBeenSet)
  {
   payload.WithString("DatabaseName", m_databaseName);

  }

  if(m_descriptionHasBeenSet)
  {
   payload.WithString("Description", m_description);

  }

  if(m_ownerHasBeenSet)
  {
   payload.WithString("Owner", m_owner);

  }

  if(m_createTimeHasBeenSet)
  {
   payload.WithDouble("CreateTime", m_createTime.SecondsWithMSPrecision());
  }

  if(m_updateTimeHasBeenSet)
  {
   payload.WithDouble("UpdateTime", m_updateTime.SecondsWithMSPrecision());
  }

  if(m_lastAccessTimeHasBeenSet)
  {
   payload.WithDouble("LastAccessTime", m_lastAccessTime.SecondsWithMSPrecision());
  }

  if(m_lastAnalyzedTimeHasBeenSet)
  {
   payload.WithDouble("LastAnalyzedTime", m_lastAnalyzedTime.SecondsWithMSPrecision());
  }

  if(m_retentionHasBeenSet)
  {
   payload.WithInteger("Retention", m_retention);

  }

  if(m_storageDescriptorHasBeenSet)
  {
   payload.WithObject("StorageDescriptor", m_storageDescriptor.Jsonize());

  }

  if(m_partitionKeysHasBeenSet)
  {
   Array<JsonValue> partitionKeysJsonList(m_partitionKeys.size());
   for(unsigned partitionKeysIndex = 0; partitionKeysIndex < partitionKeysJsonList.GetLength(); ++partitionKeysIndex)
   {
     partitionKeysJsonList[partitionKeysIndex].AsObject(m_partitionKeys[partitionKeysIndex].Jsonize());
   }
   payload.WithArray("PartitionKeys", std::move(partitionKeysJsonList));

  }

  if(m_viewOriginalTextHasBeenSet)
  {
   payload.WithString("ViewOriginalText", m_viewOriginalText);

  }

  if(m_viewExpandedTextHasBeenSet)
  {
   payload.WithString("ViewExpandedText", m_viewExpandedText);

  }

  if(m_tableTypeHasBeenSet)
  {
   payload.WithString("TableType", m_tableType);

  }

  if(m_parametersHasBeenSet)
  {
   JsonValue parametersJsonMap;
   for(auto& parametersItem : m_parameters)
   {
     parametersJsonMap.WithString(parametersItem.first, parametersItem.second);
   }
   payload.WithObject("Parameters", std::move(parametersJsonMap));

  }

  if(m_createdByHasBeenSet)
  {
   payload.WithString("CreatedBy", m_createdBy);

  }

  return payload;
}

} // namespace Model
} // namespace Glue
} // namespace Aws
