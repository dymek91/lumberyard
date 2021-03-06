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
#pragma once

#include <qbytearray.h>

#include <AzCore/Math/Vector2.h>
#include <AzCore/std/containers/unordered_set.h>

#include <GraphCanvas/Types/GraphCanvasGraphData.h>

namespace GraphCanvas
{
    //! Class for storing Entities that will be serialized to the Clipboard
    //! This class will delete the stored entities in the destructor therefore
    //! any entities that should not be owned by this class should be removed
    //! before destruction
    class GraphSerialization
    {
    public:
        AZ_TYPE_INFO(GraphSerialization, "{DB95F1F9-BEEA-499F-A6AD-1492435768F8}");
        AZ_CLASS_ALLOCATOR(GraphSerialization, AZ::SystemAllocator, 0);

        static void Reflect(AZ::ReflectContext* context);

        GraphSerialization() = default;

        explicit GraphSerialization(AZStd::string serializationKey);
        explicit GraphSerialization(const QByteArray& dataArray);
        explicit GraphSerialization(GraphSerialization&& other);

        ~GraphSerialization() = default;

        GraphSerialization& operator=(GraphSerialization&& other);

        void Clear();
        
        const AZStd::string& GetSerializationKey() const;
        void SetAveragePosition(const AZ::Vector2& averagePosition);

        const AZ::Vector2& GetAveragePosition() const;

        GraphData& GetGraphData();
        const GraphData& GetGraphData() const;

        AZStd::unordered_map<AZStd::string, AZStd::any>& GetUserDataMapRef();
        const AZStd::unordered_map<AZStd::string, AZStd::any>& GetUserDataMapRef() const;

        AZ::EntityId FindRemappedEntityId(const AZ::EntityId& originalId) const;
        void RegenerateIds();

    private:

        // The key to help decide which targets are valid for this serialized data at the graph canvas level.
        AZStd::string                                   m_serializationKey;

        // The Scene data to be copied.
        GraphData                                 m_graphData;
        AZ::Vector2                                     m_averagePosition;

        // Custom serializable fields for adding custom user data to the serialization
        AZStd::unordered_map<AZStd::string, AZStd::any> m_userFields;
        AZStd::unordered_map<AZ::EntityId, AZ::EntityId> m_newIdMapping;
    };
}
