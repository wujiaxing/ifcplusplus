/* -*-c++-*- IfcPlusPlus - www.ifcplusplus.com - Copyright (C) 2011 Fabian Gerold
*
* This library is open source and may be redistributed and/or modified under  
* the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or 
* (at your option) any later version.  The full license is in LICENSE file
* included with this distribution, and on the openscenegraph.org website.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
* OpenSceneGraph Public License for more details.
*/
#include <sstream>
#include <limits>

#include "ifcpp/model/IfcPPException.h"
#include "ifcpp/model/IfcPPAttributeObject.h"
#include "ifcpp/model/IfcPPGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IfcPPEntityEnums.h"
#include "include/IfcAppliedValue.h"
#include "include/IfcConstructionResource.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcPhysicalQuantity.h"
#include "include/IfcRelAggregates.h"
#include "include/IfcRelAssigns.h"
#include "include/IfcRelAssignsToResource.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelDeclares.h"
#include "include/IfcRelDefinesByObject.h"
#include "include/IfcRelDefinesByProperties.h"
#include "include/IfcRelDefinesByType.h"
#include "include/IfcRelNests.h"
#include "include/IfcResourceTime.h"
#include "include/IfcText.h"

// ENTITY IfcConstructionResource 
IfcConstructionResource::IfcConstructionResource() { m_entity_enum = IFCCONSTRUCTIONRESOURCE; }
IfcConstructionResource::IfcConstructionResource( int id ) { m_id = id; m_entity_enum = IFCCONSTRUCTIONRESOURCE; }
IfcConstructionResource::~IfcConstructionResource() {}
shared_ptr<IfcPPObject> IfcConstructionResource::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcConstructionResource> copy_self( new IfcConstructionResource() );
	if( m_GlobalId )
	{
		if( options.create_new_IfcGloballyUniqueId ) { copy_self->m_GlobalId = shared_ptr<IfcGloballyUniqueId>(new IfcGloballyUniqueId( CreateCompressedGuidString22() ) ); }
		else { copy_self->m_GlobalId = dynamic_pointer_cast<IfcGloballyUniqueId>( m_GlobalId->getDeepCopy(options) ); }
	}
	if( m_OwnerHistory )
	{
		if( options.shallow_copy_IfcOwnerHistory ) { copy_self->m_OwnerHistory = m_OwnerHistory; }
		else { copy_self->m_OwnerHistory = dynamic_pointer_cast<IfcOwnerHistory>( m_OwnerHistory->getDeepCopy(options) ); }
	}
	if( m_Name ) { copy_self->m_Name = dynamic_pointer_cast<IfcLabel>( m_Name->getDeepCopy(options) ); }
	if( m_Description ) { copy_self->m_Description = dynamic_pointer_cast<IfcText>( m_Description->getDeepCopy(options) ); }
	if( m_ObjectType ) { copy_self->m_ObjectType = dynamic_pointer_cast<IfcLabel>( m_ObjectType->getDeepCopy(options) ); }
	if( m_Identification ) { copy_self->m_Identification = dynamic_pointer_cast<IfcIdentifier>( m_Identification->getDeepCopy(options) ); }
	if( m_LongDescription ) { copy_self->m_LongDescription = dynamic_pointer_cast<IfcText>( m_LongDescription->getDeepCopy(options) ); }
	if( m_Usage ) { copy_self->m_Usage = dynamic_pointer_cast<IfcResourceTime>( m_Usage->getDeepCopy(options) ); }
	for( size_t ii=0; ii<m_BaseCosts.size(); ++ii )
	{
		auto item_ii = m_BaseCosts[ii];
		if( item_ii )
		{
			copy_self->m_BaseCosts.push_back( dynamic_pointer_cast<IfcAppliedValue>(item_ii->getDeepCopy(options) ) );
		}
	}
	if( m_BaseQuantity ) { copy_self->m_BaseQuantity = dynamic_pointer_cast<IfcPhysicalQuantity>( m_BaseQuantity->getDeepCopy(options) ); }
	return copy_self;
}
void IfcConstructionResource::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "= IFCCONSTRUCTIONRESOURCE" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->m_id; } else { stream << "*"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_ObjectType ) { m_ObjectType->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_Identification ) { m_Identification->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_LongDescription ) { m_LongDescription->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_Usage ) { stream << "#" << m_Usage->m_id; } else { stream << "$"; }
	stream << ",";
	writeEntityList( stream, m_BaseCosts );
	stream << ",";
	if( m_BaseQuantity ) { stream << "#" << m_BaseQuantity->m_id; } else { stream << "$"; }
	stream << ");";
}
void IfcConstructionResource::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcConstructionResource::readStepArguments( const std::vector<std::wstring>& args, const boost::unordered_map<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args != 10 ){ std::stringstream err; err << "Wrong parameter count for entity IfcConstructionResource, expecting 10, having " << num_args << ". Entity ID: " << m_id << std::endl; throw IfcPPException( err.str().c_str() ); }
	m_GlobalId = IfcGloballyUniqueId::createObjectFromSTEP( args[0] );
	readEntityReference( args[1], m_OwnerHistory, map );
	m_Name = IfcLabel::createObjectFromSTEP( args[2] );
	m_Description = IfcText::createObjectFromSTEP( args[3] );
	m_ObjectType = IfcLabel::createObjectFromSTEP( args[4] );
	m_Identification = IfcIdentifier::createObjectFromSTEP( args[5] );
	m_LongDescription = IfcText::createObjectFromSTEP( args[6] );
	readEntityReference( args[7], m_Usage, map );
	readEntityReferenceList( args[8], m_BaseCosts, map );
	readEntityReference( args[9], m_BaseQuantity, map );
}
void IfcConstructionResource::getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
	IfcResource::getAttributes( vec_attributes );
	vec_attributes.push_back( std::make_pair( "Usage", m_Usage ) );
	if( m_BaseCosts.size() > 0 )
	{
		shared_ptr<IfcPPAttributeObjectVector> BaseCosts_vec_object( new  IfcPPAttributeObjectVector() );
		std::copy( m_BaseCosts.begin(), m_BaseCosts.end(), std::back_inserter( BaseCosts_vec_object->m_vec ) );
		vec_attributes.push_back( std::make_pair( "BaseCosts", BaseCosts_vec_object ) );
	}
	vec_attributes.push_back( std::make_pair( "BaseQuantity", m_BaseQuantity ) );
}
void IfcConstructionResource::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes_inverse )
{
	IfcResource::getAttributesInverse( vec_attributes_inverse );
}
void IfcConstructionResource::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcResource::setInverseCounterparts( ptr_self_entity );
}
void IfcConstructionResource::unlinkFromInverseCounterparts()
{
	IfcResource::unlinkFromInverseCounterparts();
}
