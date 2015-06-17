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
#include <aws/elasticloadbalancing/model/PolicyDescription.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::ElasticLoadBalancing::Model;
using namespace Aws::Utils::Xml;
using namespace Aws::Utils;

PolicyDescription::PolicyDescription() : 
    m_policyNameHasBeenSet(false),
    m_policyTypeNameHasBeenSet(false),
    m_policyAttributeDescriptionsHasBeenSet(false)
{
}

PolicyDescription::PolicyDescription(const XmlNode& xmlNode) : 
    m_policyNameHasBeenSet(false),
    m_policyTypeNameHasBeenSet(false),
    m_policyAttributeDescriptionsHasBeenSet(false)
{
  *this = xmlNode;
}

PolicyDescription& PolicyDescription::operator =(const XmlNode& xmlNode)
{
  XmlNode resultNode = xmlNode;

  if(!resultNode.IsNull())
  {
    XmlNode policyNameNode = resultNode.FirstChild("PolicyName");
    if(!policyNameNode.IsNull())
    {
      m_policyName = StringUtils::Trim(policyNameNode.GetText().c_str());
      m_policyNameHasBeenSet = true;
    }
    XmlNode policyTypeNameNode = resultNode.FirstChild("PolicyTypeName");
    if(!policyTypeNameNode.IsNull())
    {
      m_policyTypeName = StringUtils::Trim(policyTypeNameNode.GetText().c_str());
      m_policyTypeNameHasBeenSet = true;
    }
    XmlNode policyAttributeDescriptionsNodeParent = resultNode.FirstChild("PolicyAttributeDescriptions");
    XmlNode policyAttributeDescriptionsNode = policyAttributeDescriptionsNodeParent.FirstChild("member");
    if(!policyAttributeDescriptionsNode.IsNull())
    {
      while(!policyAttributeDescriptionsNode.IsNull())
      {
        m_policyAttributeDescriptions.push_back(policyAttributeDescriptionsNode);
        policyAttributeDescriptionsNode = policyAttributeDescriptionsNode.NextNode("member");
      }

      m_policyAttributeDescriptionsHasBeenSet = true;
    }
  }

  return *this;
}

void PolicyDescription::OutputToStream(Aws::OStream& oStream, const char* location, unsigned index, const char* locationValue) const
{
  if(m_policyNameHasBeenSet)
  {
      oStream << location << index << locationValue << ".PolicyName=" << StringUtils::URLEncode(m_policyName.c_str()) << "&";
  }
  if(m_policyTypeNameHasBeenSet)
  {
      oStream << location << index << locationValue << ".PolicyTypeName=" << StringUtils::URLEncode(m_policyTypeName.c_str()) << "&";
  }
  if(m_policyAttributeDescriptionsHasBeenSet)
  {
      for(auto& item : m_policyAttributeDescriptions)
      {
        Aws::StringStream policyAttributeDescriptionsSs;
        policyAttributeDescriptionsSs << location << index << locationValue << ".PolicyAttributeDescriptions";
        item.OutputToStream(oStream, policyAttributeDescriptionsSs.str().c_str());
      }
  }
}

void PolicyDescription::OutputToStream(Aws::OStream& oStream, const char* location) const
{
  if(m_policyNameHasBeenSet)
  {
      oStream << location << ".PolicyName=" << StringUtils::URLEncode(m_policyName.c_str()) << "&";
  }
  if(m_policyTypeNameHasBeenSet)
  {
      oStream << location << ".PolicyTypeName=" << StringUtils::URLEncode(m_policyTypeName.c_str()) << "&";
  }
  if(m_policyAttributeDescriptionsHasBeenSet)
  {
      for(auto& item : m_policyAttributeDescriptions)
      {
        Aws::String locationAndListMember(location);
        locationAndListMember += ".PolicyAttributeDescriptions";
        item.OutputToStream(oStream, locationAndListMember.c_str());
      }
  }
}