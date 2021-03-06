/*
	This source file is part of Rigs of Rods
	Copyright 2005-2012 Pierre-Michel Ricordel
	Copyright 2007-2012 Thomas Fischer
	Copyright 2013-2014 Petr Ohlidal

	For more information, see http://www.rigsofrods.com/

	Rigs of Rods is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License version 3, as
	published by the Free Software Foundation.

	Rigs of Rods is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Rigs of Rods.  If not, see <http://www.gnu.org/licenses/>.
*/

/**	
	@file   RigSpawner.h
	@brief  Vehicle spawning logic.
	@author Petr Ohlidal
	@date   12/2013
*/

#pragma once

#include "RoRPrerequisites.h"
#include "RigDef_Parser.h"
#include "BeamData.h"

#include <OgreString.h>

/**
* Processes rig-file-parser output into actual simulation data structures.
*
* Function writing convention:
*
* - Process*(Definition & def) 
*       Transform elements of .truck file to rig structures.
* - FindAndProcess*(Definition & def) 
*       Find and process an element which should be unique in the current vehicle configuration.
* - Add*(), Create*() or Build*() 
*       Add partial structures to rig.
* - Other functions are utilities.
*
* @author Petr Ohlidal
*/
class RigSpawner
{
	friend class VideoCamera; /* Needs to add log messages */

public:

	struct Message
	{
		enum Type
		{
			TYPE_INFO,
			TYPE_WARNING,
			TYPE_ERROR,
			TYPE_INTERNAL_ERROR,

			TYPE_INVALID = 0xFFFFFFFF
		};

		Message(
			Message::Type type, 
			Ogre::String const & text,
			RigDef::File::Keyword keyword = RigDef::File::KEYWORD_INVALID
		):
			type(type),
			text(text),
			keyword(keyword)
		{}		

		Ogre::String text;
		Type type;
		RigDef::File::Keyword keyword;
	};

	class Exception: public std::runtime_error
	{
	public:

		Exception(Ogre::String const & message):
			runtime_error(message)
		{}

	};

	void Setup( 
		Beam *rig,
		boost::shared_ptr<RigDef::File> file,
		Ogre::SceneNode *parent,
		Ogre::Vector3 const & spawn_position,
		Ogre::Quaternion const & spawn_rotation
		);

	rig_t *SpawnRig();

	/**
	* Adds a vehicle module to the validated configuration.
	* @param module_name A module from the validated rig-def file.
	*/
	bool AddModule(Ogre::String const & module_name);

	/**
	* Adds a vehicle module to the validated configuration.
	* @param module_name A module from the validated rig-def file.
	*/
	void AddModule(boost::shared_ptr<RigDef::File::Module> module)
	{
		m_selected_modules.push_back(module);
	}

	Beam *GetRig()
	{
		return m_rig;
	}

	/**
	* Finds and clones given material. Reports errors.
	* @return NULL Ogre::MaterialPtr on error.
	*/
	Ogre::MaterialPtr CloneMaterial(Ogre::String const & source_name, Ogre::String const & clone_name);

	/**
	* Finds existing node by Node::Id; throws an exception if the node doesn't exist.
	* @return Index of existing node
	* @throws Exception If the node isn't found.
	*/
	unsigned int GetNodeIndexOrThrow(RigDef::Node::Id & id);

	static void RecalculateBoundingBoxes(rig_t *rig);

	static void SetupDefaultSoundSources(Beam *vehicle);

	std::list<Message> & GetMessages()
	{
		return m_messages;
	}

	static bool CheckSoundScriptLimit(Beam *vehicle, unsigned int count);

protected:

/* -------------------------------------------------------------------------- */
/* Processing functions.
/* NOTE: Please maintain alphabetical order.
/* -------------------------------------------------------------------------- */

	/**
	* Section 'airbrakes'.
	*/
	void ProcessAirbrake(RigDef::Airbrake & def);

	/**
	* Section 'animators'.
	*/
	void ProcessAnimator(RigDef::Animator & def);

	/**
	* Section 'AntiLockBrakes'.
	*/
	void ProcessAntiLockBrakes(RigDef::AntiLockBrakes & def);

	/**
	* Section 'author' in root module.
	*/
	void ProcessAuthors();

	/**
	* Section 'axles'.
	*/
	void ProcessAxle(RigDef::Axle & def);

	/**
	* Section 'beams'. Depends on 'nodes'
	*/
	void ProcessBeam(RigDef::Beam & def);

	/**
	* Section 'brakes' in any module.
	*/
	void ProcessBrakes(RigDef::Brakes & def);

	/**
	* Section 'camerarail', depends on 'nodes'.
	*/
	void ProcessCameraRail(RigDef::CameraRail & def);

	/**
	* Section 'cameras', depends on 'nodes'.
	*/
	void ProcessCamera(RigDef::Camera & def);

	/**
	* Section 'cinecam', depends on 'nodes'.
	*/
	void ProcessCinecam(RigDef::Cinecam & def);

	/**
	* Section 'collisionboxes'
	*/
	void ProcessCollisionBox(RigDef::CollisionBox & def);

	/**
	* Processes sections 'commands' and 'commands2' (unified).
	*/
	void ProcessCommand(RigDef::Command2 & def);

	/**
	* Section 'contacters'.
	*/
	void ProcessContacter(RigDef::Node::Id & node);

	/**
	* Section 'cruisecontrol' in any module.
	*/
	void ProcessCruiseControl(RigDef::CruiseControl & def);

	/**
	* Section 'engine' in any module.
	*/
	void ProcessEngine(RigDef::Engine & def);

	/**
	* Section 'engoption' in any module.
	*/ 
	void ProcessEngoption(RigDef::Engoption & def);

	/**
	* Section 'engturbo' in any module.
	*/
	void ProcessEngturbo(RigDef::Engturbo & def);

	/**
	* Section 'exhausts'.
	*/
	void ProcessExhaust(RigDef::Exhaust & def);

	/**
	* Inline-section 'extcamera'.
	*/
	void ProcessExtCamera(RigDef::ExtCamera & def);

	/**
	* Section 'fileinfo' in root module
	*/
	void ProcessFileInfo();

	/**
	* Sections 'flares' and 'flares2'.
	*/
	void ProcessFlare2(RigDef::Flare2 & def);

	/**
	* Section 'flexbodies'.
	*/
	void ProcessFlexbody(boost::shared_ptr<RigDef::Flexbody> def);

	/**
	* Section 'flexbodywheels'.
	*/
	void ProcessFlexBodyWheel(RigDef::FlexBodyWheel & def);

	/**
	* Section 'fusedrag'.
	*/
	void ProcessFusedrag(RigDef::Fusedrag & def);

	/**
	* Section 'gobals' in any module
	*/
	void ProcessGlobals(RigDef::Globals & def);

	/**
	* Section 'guisettings'.
	*/
	void ProcessGuiSettings(RigDef::GuiSettings & def);

	void ProcessHelp();

	/**
	* Depends on 'nodes'
	*/
	void ProcessHook(RigDef::Hook & def);

	void ProcessHydro(RigDef::Hydro & def);

	/**
	* Depends on section 'nodes'
	*/
	void ProcessLockgroup(RigDef::Lockgroup & lockgroup);

	/**
	* Section 'managedmaterials'
	*/
	void ProcessManagedMaterial(RigDef::ManagedMaterial & def);

	/**
	* Section 'materialflarebindings'.
	*/
	void ProcessMaterialFlareBinding(RigDef::MaterialFlareBinding & def);

	/**
	* Section 'meshwheels'.
	*/
	void ProcessMeshWheel(RigDef::MeshWheel & meshwheel_def);

	/**
	* Section 'meshwheels2'.
	*/
	void ProcessMeshWheel2(RigDef::MeshWheel2 & def);

	/**
	* Section 'minimass'.
	*/
	void ProcessMinimassInAnyModule();

	void ProcessNode(RigDef::Node & def);

	/**
	* Section 'particles'.
	*/
	void ProcessParticle(RigDef::Particle & def);

	/**
	* Section 'pistonprops'.
	*/
	void ProcessPistonprop(RigDef::Pistonprop & def);

	/**
	* Section 'props'.
	*/
	void ProcessProp(RigDef::Prop & def);

	/**
	* Section 'railgroups'.
	*/
	void ProcessRailGroup(RigDef::RailGroup & def);

	/**
	* Section 'ropables'.
	*/
	void ProcessRopable(RigDef::Ropable & def);

	/**
	* Section 'ropes'.
	*/
	void ProcessRope(RigDef::Rope & def);

	void ProcessRotator(RigDef::Rotator & def);

	void ProcessRotator2(RigDef::Rotator2 & def);

	void ProcessScrewprop(RigDef::Screwprop & def);

	/**
	* Section 'shocks'.
	*/
	void ProcessShock(RigDef::Shock & def);

	/**
	* Add a shock absorber (section 'shocks2') to the rig.
	*/
	void ProcessShock2(RigDef::Shock2 & def);

	void ProcessSkeletonSettings(RigDef::SkeletonSettings & def);

	/**
	* Section 'slidenodes'. Depends on 'railgroups'
	*/
	void ProcessSlidenode(RigDef::SlideNode & def);

	/**
	* Section 'SlopeBrake' in any module.
	*/
	void ProcessSlopeBrake(RigDef::SlopeBrake & def);

	/**
	* Section 'soundsources'.
	*/
	void ProcessSoundSource(RigDef::SoundSource & def); 

	/**
	* Section 'soundsources2'.
	*/
	void ProcessSoundSource2(RigDef::SoundSource2 & def); 

	/**
	* Section 'SlopeBrake' in any module.
	*/
	void ProcessSpeedLimiter(RigDef::SpeedLimiter & def);

	/**
	* Section 'submeshes'.
	*/
	void ProcessSubmesh(RigDef::Submesh & def);

	/**
	* Inline-section 'submesh_groundmodel'.
	*/
	void ProcessSubmeshGroundmodel();

	/**
	* Section 'ties'.
	*/
	void ProcessTie(RigDef::Tie & def);

	/**
	* Section 'torquecurve' in any module. Depends on 'engine'.
	*/
	void ProcessTorqueCurve(RigDef::TorqueCurve & def);

	/**
	* Section 'TractionControl' in any module.
	*/
	void ProcessTractionControl(RigDef::TractionControl & def);

	void ProcessTrigger(RigDef::Trigger & def);

	void ProcessTurbojet(RigDef::Turbojet & def);

	/**
	* Sections 'turboprops' and 'turboprops2'
	*/
	void ProcessTurboprop2(RigDef::Turboprop2 & def);

	/**
	* Section 'videocamera'.
	*/
	void ProcessVideoCamera(RigDef::VideoCamera & def);

	/**
	* Section 'wheels' in all modules.
	*/
	void ProcessWheel(RigDef::Wheel & def);

	/**
	* Section 'wheels2' in all modules.
	* @author Pierre-Michel Ricordel
	* @author Thomas Fischer
	*/
	void ProcessWheel2(RigDef::Wheel2 & def);

	/**
	* Section 'wings'.
	* @author 
	*/
	void ProcessWing(RigDef::Wing & def);

/* -------------------------------------------------------------------------- */
/* Partial processing functions.
/* -------------------------------------------------------------------------- */

	void BuildAerialEngine(
		int ref_node_index,
		int back_node_index,
		int blade_1_node_index,
		int blade_2_node_index,
		int blade_3_node_index,
		int blade_4_node_index,
		int couplenode_index,
		bool is_turboprops,
		Ogre::String const & airfoil,
		float power,
		float pitch
	);

	/**
	* Fetches free beam and sets up defaults.
	*/
	beam_t & AddBeam(
		node_t & node_1, 
		node_t & node_2, 
		boost::shared_ptr<RigDef::BeamDefaults> & defaults,
		int detacher_group
	);

	/**
	* Adds visuals to wheel from section 'wheels'.
	*/
	void CreateWheelVisuals(
		unsigned int wheel_index, 
		RigDef::Wheel & wheel_def, 
		unsigned int node_base_index
	);

	/**
	* Adds complete wheel (section 'wheels') to the rig.
	* @return wheel index in rig_t::wheels array.
	*/
	unsigned int AddWheel(RigDef::Wheel & wheel);

	/**
	* Adds wheel from section 'wheels2'.
	* @return wheel index.
	*/
	unsigned int AddWheel2(RigDef::Wheel2 & wheel_2_def);

	void CreateBeamVisuals(beam_t & beam, int beam_index, RigDef::BeamDefaults & beam_defaults, bool activate);

	Rail *CreateRail(std::vector<RigDef::Node::Range> & node_ranges);

	static void AddSoundSource(Beam *vehicle, SoundScriptInstance *sound_script, int node_index, int type = -2);

	static void AddSoundSourceInstance(Beam *vehicle, Ogre::String const & sound_script_name, int node_index, int type = -2);

/* -------------------------------------------------------------------------- */
/* Limits.
/* -------------------------------------------------------------------------- */

	/**
	* Checks there is still space left in rig_t::nodes array.
	* @param count Required number of free slots.
	* @return True if there is space left.
	*/
	bool CheckNodeLimit(unsigned int count);
	
	/**
	* Checks there is still space left in rig_t::beams array.
	* @param count Required number of free slots.
	* @return True if there is space left.
	*/
	bool CheckBeamLimit(unsigned int count);

	/**
	* Checks there is still space left in rig_t::shocks array.
	* @param count Required number of free slots.
	* @return True if there is space left.
	*/
	bool CheckShockLimit(unsigned int count);

	/**
	* Checks there is still space left in rig_t::hydro array.
	* @param count Required number of free slots.
	* @return True if there is space left.
	*/
	bool CheckHydroLimit(unsigned int count);

	/**
	* Checks there is still space left in rig_t::rotators array.
	* @param count Required number of free slots.
	* @return True if there is space left.
	*/
	bool CheckRotatorLimit(unsigned int count);

	/**
	* Checks there is still space left in rig_t::cparticles array.
	* @param count Required number of free slots.
	* @return True if there is space left.
	*/
	bool CheckParticleLimit(unsigned int count);
	
	/**
	* Checks there is still space left in rig_t::axles array.
	* @param count Required number of free slots.
	* @return True if there is space left.
	*/
	bool CheckAxleLimit(unsigned int count);

	/**
	* Checks there is still space left in rig_t::props array.
	* @param count Required number of free slots.
	* @return True if there is space left.
	*/
	bool CheckPropLimit(unsigned int count);

	/**
	* Checks there is still space left in rig_t::flexbodies array.
	* @param count Required number of free slots.
	* @return True if there is space left.
	*/
	bool CheckFlexbodyLimit(unsigned int count);

	/**
	* Checks there is still space left in rig_t::subtexcoords, rig_t::subcabs and rig_t::subisback arrays.
	* @param count Required number of free slots.
	* @return True if there is space left.
	*/
	bool CheckSubmeshLimit(unsigned int count);

	/**
	* Checks there is still space left in rig_t::texcoords array.
	* @param count Required number of free slots.
	* @return True if there is space left.
	*/
	bool CheckTexcoordLimit(unsigned int count);

	/**
	* Checks there is still space left in rig_t::cabs array.
	* @param count Required number of free slots.
	* @return True if there is space left.
	*/
	bool CheckCabLimit(unsigned int count);

	/**
	* Checks there is still space left in rig_t::cameraRail array.
	* @param count Required number of free slots.
	* @return True if there is space left.
	*/
	bool CheckCameraRailLimit(unsigned int count);

	/**
	* Checks there is still space left in rig_t::soundsources array.
	* @param count Required number of free slots.
	* @return True if there is space left.
	*/
	bool CheckSoundScriptLimit(unsigned int count);

	/**
	* Checks there is still space left in rig_t::soundsources array (static version).
	* @param count Required number of free slots.
	* @return True if there is space left.
	*/
	static bool CheckSoundScriptLimit(rig_t *vehicle, unsigned int count);

	/**
	* Checks there is still space left in rig_t::soundsources array.
	* @param count Required number of free slots.
	* @return True if there is space left.
	*/
	bool CheckWingLimit(unsigned int count);

	/**
	* Checks there is still space left in rig_t::airbrakes array.
	* @param count Required number of free slots.
	* @return True if there is enough space left.
	*/
	bool CheckAirBrakeLimit(unsigned int count);

	/**
	* Checks there is still space left in rig_t::aeroengines array.
	* @param count Required number of free slots.
	* @return True if there is enough space left.
	*/
	bool CheckAeroEngineLimit(unsigned int count);

	/**
	* Checks there is still space left in rig_t::screwprops array.
	* @param count Required number of free slots.
	* @return True if there is enough space left.
	*/
	bool CheckScrewpropLimit(unsigned int count);

/* -------------------------------------------------------------------------- */
/* Utility functions.
/* -------------------------------------------------------------------------- */

	/**
	* Seeks node. Tolerates non-existent numbered-nodes (backwards compatibility)
	* @return Pointer to node. If node is indexed and doesn't exist, returns pointer to un-initialised object. Returns nullptr if node is named and doesn't exist.
	*/
	node_t* GetBeamNodePointer(RigDef::Node::Id & id);

	/**
	* Seeks node in both RigDef::File definition and rig_t generated rig.
	* @return Node index or -1 if the node was not found.
	*/
	int FindNodeIndex(RigDef::Node::Id & id, bool silent = false);

	/**
	* Seeks node in both RigDef::File definition and rig_t generated rig. Tolerates numbered nodes which weren't found (backwards compatibility)
	* @return Node index or -1 if the node was named and not found (not found numbered nodes pass through, for compatibility).
	*/
	int FindNodeIndex_AcceptNonExistentNumbered(RigDef::Node::Id & node_id);

	/**
	* Finds a generated node in rig.
	* @return Pointer to node, or nullptr if node doesn't exist.
	*/
	node_t* FindGeneratedNodeInRig(RigDef::Node::Id & id, bool silent = false);

	/**
	* Finds wheel with given axle nodes and returns it's index.
	* @param _out_axle_wheel Index of the found wheel.
	* @return True if wheel was found, false if not.
	*/
	bool AssignWheelToAxle(int & _out_axle_wheel, node_t *axis_node_1, node_t *axis_node_2);

	float ComputeWingArea(
		Ogre::Vector3 const & ref, 
		Ogre::Vector3 const & x, 
		Ogre::Vector3 const & y, 
		Ogre::Vector3 const & aref
	);

	/**
	* Adds a node to the rig.
	* @return First: node index, second: True if the node was inserted, false if duplicate.
	*/
	std::pair<unsigned int, bool> AddNode(RigDef::Node::Id & id);

	/**
	* Adds a message to internal log.
	*/
	void AddMessage(Message::Type type, Ogre::String const & text);

	void AddExhaust(
		unsigned int emitter_node_idx,
		unsigned int direction_node_idx,
		bool old_format,
		Ogre::String *user_material_name
	);

	/**
	* Finds existing node by Node::Id
	* @return First: Index of existing node; Second: true if node was found.
	*/
	std::pair<unsigned int, bool> GetNodeIndex(RigDef::Node::Id & id, bool quiet = false);

	/**
	* Finds existing node by Node::Id
	* @return Pointer to node or nullptr if not found.
	*/
	node_t* GetNodePointer(RigDef::Node::Id & id);

	/**
	* Finds existing node by Node::Id
	* @return Pointer to node
	* @throws Exception If the node isn't found.
	*/
	node_t* GetNodePointerOrThrow(RigDef::Node::Id & id);

	/**
	* Finds existing node by Node::Id; throws an exception if the node doesn't exist.
	* @return Reference to existing node.
	* @throws Exception If the node isn't found.
	*/
	node_t & GetNodeOrThrow(RigDef::Node::Id & id);

	/**
	* Finds existing pointer by Node::Id
	* @return Ref. to node.
	*/
	node_t & GetNode(RigDef::Node::Id & id)
	{
		node_t * node = GetNodePointer(id);
		if (node == nullptr)
		{
			throw Exception("Failed to retrieve node.");
		}
		return * node;
	}

	/**
	* Finds existing node by index.
	* @return Pointer to node or nullptr if not found.
	*/
	node_t & GetNode(unsigned int node_index);

	/**
	* Sets up defaults & position of a node.
	*/
	void InitNode(node_t & node, Ogre::Vector3 const & position);

	/**
	* Sets up defaults & position of a node.
	*/
	void InitNode(unsigned int node_index, Ogre::Vector3 const & position);

	/**
	* Sets up defaults & position of a node.
	*/
	void InitNode(
		node_t & node, 
		Ogre::Vector3 const & position,
		boost::shared_ptr<RigDef::NodeDefaults> node_defaults
	);

	/**
	* Setter.
	*/
	void SetCurrentKeyword(RigDef::File::Keyword keyword)
	{
		m_current_keyword = keyword;
	}

	beam_t & GetBeam(unsigned int index);

	/**
	* Parses list of node-ranges into list of individual nodes.
	* @return False if some nodes could not be found and thus the lookup wasn't completed.
	*/
	bool CollectNodesFromRanges(
		std::vector<RigDef::Node::Range> & node_ranges,
		std::vector<unsigned int> & out_node_indices
	);

	/**
	* Gets a free node slot; checks limits, sets it's array position and updates 'free_node' index.
	* @return A reference to node slot.
	*/
	node_t & GetFreeNode();

	/**
	* Gets a free beam slot; checks limits, sets it's array position and updates 'free_beam' index.
	* @return A reference to beam slot.
	*/
	beam_t & GetFreeBeam();

	/**
	* Gets a free beam slot; Sets up defaults & position of a node.
	* @return A reference to node slot.
	*/
	node_t & GetAndInitFreeNode(Ogre::Vector3 const & position);

	/**
	* Gets a free beam slot; checks limits, sets it's array position and updates 'rig_t::free_beam' index.
	* @return A reference to beam slot.
	*/
	beam_t & GetAndInitFreeBeam(node_t & node_1, node_t & node_2);

	shock_t & GetFreeShock();

	/**
	* Sets up nodes & length of a beam.
	*/
	void InitBeam(beam_t & beam, node_t *node_1, node_t *node_2);

	/**
	* Transforms wheel from 'wheels2' section format to 'wheels' section format.
	*/
	RigDef::Wheel DowngradeWheel2(RigDef::Wheel2 & wheel_2);

	void CalculateBeamLength(beam_t & beam);

	void SetBeamStrength(beam_t & beam, float strength);

	void SetBeamSpring(beam_t & beam, float spring);

	void SetBeamDamping(beam_t & beam, float damping);

	beam_t *FindBeamInRig(unsigned int node_a, unsigned int node_b);

	void SetBeamDeformationThreshold(beam_t & beam, boost::shared_ptr<RigDef::BeamDefaults> beam_defaults);

	void CreateBeamVisuals(beam_t &beam, int index, bool attach_entity_to_scene);

	/**
	* Finds node with lowest Y in spawned rig.
	*/
	int FindLowestNodeInRig();

	//void SetBeamPlasticCoefficient(beam_t & beam, boost::shared_ptr<RigDef::BeamDefaults> beam_defaults);

	/**
	* Checks a section only appears in one module and reports a warning if not.
	*/
	void CheckSectionSingleModule(
		Ogre::String const & section_name,
		std::list<boost::shared_ptr<RigDef::File::Module>> & found_items	
	);

	/**
	* Creates beam pre-configured for use as rim with section 'wheels2'.
	*/
	unsigned int AddWheelRimBeam(RigDef::Wheel2 & wheel_2_def, node_t *node_1, node_t *node_2);

	/**
	* Creates beam pre-configured for use as tyre with section 'wheels2'.
	*/
	unsigned int AddTyreBeam(RigDef::Wheel2 & wheel_2_def, node_t *node_1, node_t *node_2);

	/**
	* Creates beam partially configured for use with section 'wheels2'.
	*/
	unsigned int _SectionWheels2AddBeam(RigDef::Wheel2 & wheel_2_def, node_t *node_1, node_t *node_2);

	/**
	* Builds complete wheel visuals (sections 'wheels', 'wheels2').
	* @param rim_ratio Percentual size of the rim.
	*/
	void CreateWheelVisuals(
		unsigned int wheel_index, 
		unsigned int node_base_index,
		unsigned int def_num_rays,
		Ogre::String const & rim_material_name,
		Ogre::String const & band_material_name,
		bool separate_rim,
		float rim_ratio = 1.f
	);

	/**
	* Adds visuals to 'wheels2' wheel.
	*/
	void CreateWheelVisuals(unsigned int wheel_index, RigDef::Wheel2 & wheel_2_def, unsigned int node_base_index);

	/**
	* Sets up wheel and builds nodes for sections 'wheels', 'meshwheels' and 'meshwheels2'.
	* @param wheel_width Width of the wheel (used in section 'wheels'). Use negative value to calculate width from axis beam.
	* @return Wheel index.
	*/
	unsigned int BuildWheelObjectAndNodes(
		unsigned int num_rays,
		node_t *axis_node_1,
		node_t *axis_node_2,
		node_t *reference_arm_node,
		unsigned int reserve_nodes,
		unsigned int reserve_beams,
		float wheel_radius,
		RigDef::Wheels::Propulsion propulsion,
		RigDef::Wheels::Braking braking,
		boost::shared_ptr<RigDef::NodeDefaults> node_defaults,
		float wheel_mass,
		bool set_param_iswheel = true,
		float wheel_width = -1.f
	);

	/**
	* Adds beams to wheels from 'wheels', 'meshwheels'
	*/
	void BuildWheelBeams(
		unsigned int num_rays,
		unsigned int base_node_index,
		node_t *axis_node_1,
		node_t *axis_node_2,
		float tyre_spring,
		float tyre_damping,
		float rim_spring,
		float rim_damping,
		boost::shared_ptr<RigDef::BeamDefaults> beam_defaults,
		RigDef::Node::Id rigidity_node_id,
		float max_extension = 0.f
	);

	/**
	* Creates beam for wheels 'wheels', 'meshwheels', 'meshwheels2'
	*/
	unsigned int AddWheelBeam(
		node_t *node_1,
		node_t *node_2,
		float spring,
		float damping,
		boost::shared_ptr<RigDef::BeamDefaults> beam_defaults,
		float max_contraction = -1.f,
		float max_extension = -1.f,
		int type = BEAM_INVISIBLE /* Anonymous enum in BeamData.h */
	);

	/**
	* Builds wheel visuals (sections 'meshwheels', 'meshwheels2').
	*/
	void BuildMeshWheelVisuals(
		unsigned int wheel_index,
		unsigned int base_node_index,
		unsigned int axis_node_1_index,
		unsigned int axis_node_2_index,
		unsigned int num_rays,
		Ogre::String mesh_name,
		Ogre::String material_name,
		float rim_radius,
		bool rim_reverse	
	);

	/**
	* From SerializedRig::wash_calculator()
	*/
	void WashCalculator(Ogre::Quaternion const & rot);

	void FetchAxisNodes(
		node_t* & axis_node_1, 
		node_t* & axis_node_2, 
		RigDef::Node::Id axis_node_1_id,
		RigDef::Node::Id axis_node_2_id
	);

	void _ProcessCommandKeyInertia(
		RigDef::OptionalInertia & inertia, 
		RigDef::DefaultInertia & inertia_defaults, 
		int contract_key, 
		int extend_key
	);

	void AdjustNodeBuoyancy(node_t & node, boost::shared_ptr<RigDef::NodeDefaults> defaults);

	/**
	* Ported from SerializedRig::loadTruck()
	*/
	void FinalizeRig();

	/**
	* Ported from SerializedRig::SerializedRig()
	*/
	void InitializeRig();

	boost::shared_ptr<RigDef::File> m_file; //!< The parsed input file.
	Beam *m_rig; //!< The output rig.
	std::list<boost::shared_ptr<RigDef::File::Module>> m_selected_modules;
	std::map<Ogre::String, unsigned int> m_named_nodes;
	std::map<unsigned int, unsigned int> m_numbered_nodes;
	std::list<Message> m_messages; //!< Message log.
	RigDef::File::Keyword m_current_keyword; //!< For error reports
	bool m_enable_background_loading;

	/* RIG CONTEXT */

	Ogre::SceneNode *m_parent_scene_node;
	Ogre::Vector3 m_spawn_position;
	Ogre::Quaternion m_spawn_rotation;
	float m_wing_area;
	int m_airplane_left_light;
	int m_airplane_right_light;
	float m_fuse_z_min;
	float m_fuse_z_max;
	float m_fuse_y_min;
	float m_fuse_y_max;
	bool  m_generate_wing_position_lights;
};
