/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/
// Original file Copyright Crytek GMBH or its affiliates, used under license.

#ifndef CRYINCLUDE_CRYCOMMONTOOLS_EXPORT_MAXUSERPROPERTYHELPERS_H
#define CRYINCLUDE_CRYCOMMONTOOLS_EXPORT_MAXUSERPROPERTYHELPERS_H
#pragma once


#include <string>

class INode;

namespace MaxUserPropertyHelpers
{
    std::string GetNodeProperties(INode* node);
    std::string GetStringNodeProperty(INode* node, const char* name, const char* defaultValue);
    float GetFloatNodeProperty(INode* node, const char* name, float defaultValue);
    int GetIntNodeProperty(INode* node, const char* name, int defaultValue);
    bool GetBoolNodeProperty(INode* node, const char* name, bool defaultValue);
}

#endif // CRYINCLUDE_CRYCOMMONTOOLS_EXPORT_MAXUSERPROPERTYHELPERS_H