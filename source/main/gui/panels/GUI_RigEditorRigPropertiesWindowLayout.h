#pragma once

// ----------------------------------------------------------------------------
// Generated by MyGUI's LayoutEditor using RoR's code templates.
//
// Find the templates at [repository]/tools/MyGUI_LayoutEditor/
// ----------------------------------------------------------------------------

#include "ForwardDeclarations.h"
#include "BaseLayout.h"

namespace RoR
{

namespace GUI
{
	
ATTRIBUTE_CLASS_LAYOUT(RigEditorRigPropertiesWindowLayout, "rig_editor_file_properties_window.layout");
class RigEditorRigPropertiesWindowLayout : public wraps::BaseLayout
{

public:

	RigEditorRigPropertiesWindowLayout(MyGUI::Widget* _parent = nullptr);
	virtual ~RigEditorRigPropertiesWindowLayout();

protected:

	//%LE Widget_Declaration list start
	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_rig_properties_window, "rig_properties_window");
	MyGUI::Window* m_rig_properties_window;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_rig_properties_tabs, "rig_properties_tabs");
	MyGUI::TabControl* m_rig_properties_tabs;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_rig_properties_basic_panel, "rig_properties_basic_panel");
	MyGUI::TabItem* m_rig_properties_basic_panel;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_title, "label_title");
	MyGUI::TextBox* m_label_title;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_guid, "label_guid");
	MyGUI::TextBox* m_label_guid;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_uid, "label_uid");
	MyGUI::TextBox* m_label_uid;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_category_id, "label_category_id");
	MyGUI::TextBox* m_label_category_id;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_version, "label_version");
	MyGUI::TextBox* m_label_version;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_description, "label_description");
	MyGUI::TextBox* m_label_description;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_editbox_title, "editbox_title");
	MyGUI::EditBox* m_editbox_title;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_editbox_guid, "editbox_guid");
	MyGUI::EditBox* m_editbox_guid;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_editbox_uid, "editbox_uid");
	MyGUI::EditBox* m_editbox_uid;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_textbox_category_id, "textbox_category_id");
	MyGUI::EditBox* m_textbox_category_id;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_editbox_version, "editbox_version");
	MyGUI::EditBox* m_editbox_version;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_editbox_description, "editbox_description");
	MyGUI::EditBox* m_editbox_description;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_authors, "label_authors");
	MyGUI::TextBox* m_label_authors;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_editbox_authors, "editbox_authors");
	MyGUI::EditBox* m_editbox_authors;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_title_doc, "label_title_doc");
	MyGUI::TextBox* m_label_title_doc;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_guid_doc, "label_guid_doc");
	MyGUI::TextBox* m_label_guid_doc;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_uid_doc, "label_uid_doc");
	MyGUI::TextBox* m_label_uid_doc;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_categoryid_doc, "label_categoryid_doc");
	MyGUI::TextBox* m_label_categoryid_doc;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_version_doc, "label_version_doc");
	MyGUI::TextBox* m_label_version_doc;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_description_doc, "label_description_doc");
	MyGUI::TextBox* m_label_description_doc;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_author_doc, "label_author_doc");
	MyGUI::TextBox* m_label_author_doc;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_checkbox_hide_in_chooser, "checkbox_hide_in_chooser");
	MyGUI::Button* m_checkbox_hide_in_chooser;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_checkbox_forwardcommands, "checkbox_forwardcommands");
	MyGUI::Button* m_checkbox_forwardcommands;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_checkbox_importcommands, "checkbox_importcommands");
	MyGUI::Button* m_checkbox_importcommands;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_checkbox_rescuer, "checkbox_rescuer");
	MyGUI::Button* m_checkbox_rescuer;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_hideinchooser, "label_hideinchooser");
	MyGUI::TextBox* m_label_hideinchooser;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_forwardcommands, "label_forwardcommands");
	MyGUI::TextBox* m_label_forwardcommands;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_importcommands, "label_importcommands");
	MyGUI::TextBox* m_label_importcommands;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_rescuer, "label_rescuer");
	MyGUI::TextBox* m_label_rescuer;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_rig_properties_audiovideo_panel, "rig_properties_audiovideo_panel");
	MyGUI::TabItem* m_rig_properties_audiovideo_panel;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_camera_behaviour, "label_camera_behaviour");
	MyGUI::TextBox* m_label_camera_behaviour;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_radio_camera_behaviour_classic, "radio_camera_behaviour_classic");
	MyGUI::Button* m_radio_camera_behaviour_classic;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_radio_camera_behaviour_cinecam, "radio_camera_behaviour_cinecam");
	MyGUI::Button* m_radio_camera_behaviour_cinecam;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_radio_camera_behaviour_node, "radio_camera_behaviour_node");
	MyGUI::Button* m_radio_camera_behaviour_node;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_editbox_extcamera_node, "editbox_extcamera_node");
	MyGUI::EditBox* m_editbox_extcamera_node;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_extcamera_doc, "label_extcamera_doc");
	MyGUI::TextBox* m_label_extcamera_doc;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_checkbox_disable_default_sounds, "checkbox_disable_default_sounds");
	MyGUI::Button* m_checkbox_disable_default_sounds;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_disable_default_sounds_doc, "label_disable_default_sounds_doc");
	MyGUI::TextBox* m_label_disable_default_sounds_doc;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_cab_material, "label_cab_material");
	MyGUI::TextBox* m_label_cab_material;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_editbox_cab_material_name, "editbox_cab_material_name");
	MyGUI::EditBox* m_editbox_cab_material_name;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_cab_material_doc, "label_cab_material_doc");
	MyGUI::TextBox* m_label_cab_material_doc;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_beam_thickness, "label_beam_thickness");
	MyGUI::TextBox* m_label_beam_thickness;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_beam_visibility, "label_beam_visibility");
	MyGUI::TextBox* m_label_beam_visibility;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_editbox_beam_thickness_meters, "editbox_beam_thickness_meters");
	MyGUI::EditBox* m_editbox_beam_thickness_meters;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_beam_thickness_units, "label_beam_thickness_units");
	MyGUI::TextBox* m_label_beam_thickness_units;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_editbox_beam_visibility_range_meters, "editbox_beam_visibility_range_meters");
	MyGUI::EditBox* m_editbox_beam_visibility_range_meters;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_beam_visibility_units, "label_beam_visibility_units");
	MyGUI::TextBox* m_label_beam_visibility_units;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_beam_thickness_doc, "label_beam_thickness_doc");
	MyGUI::TextBox* m_label_beam_thickness_doc;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_beams_visibility_doc, "label_beams_visibility_doc");
	MyGUI::TextBox* m_label_beams_visibility_doc;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_rig_properties_physics_panel, "rig_properties_physics_panel");
	MyGUI::TabItem* m_rig_properties_physics_panel;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_dry_mass, "label_dry_mass");
	MyGUI::TextBox* m_label_dry_mass;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_load_mass, "label_load_mass");
	MyGUI::TextBox* m_label_load_mass;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_minimass, "label_minimass");
	MyGUI::TextBox* m_label_minimass;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_editbox_dry_mass, "editbox_dry_mass");
	MyGUI::EditBox* m_editbox_dry_mass;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_editbox_load_mass, "editbox_load_mass");
	MyGUI::EditBox* m_editbox_load_mass;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_editbox_minimass, "editbox_minimass");
	MyGUI::EditBox* m_editbox_minimass;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_dry_mass_units, "label_dry_mass_units");
	MyGUI::TextBox* m_label_dry_mass_units;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_load_mass_units, "label_load_mass_units");
	MyGUI::TextBox* m_label_load_mass_units;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_minimass_units, "label_minimass_units");
	MyGUI::TextBox* m_label_minimass_units;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_checkbox_use_advanced_deform, "checkbox_use_advanced_deform");
	MyGUI::Button* m_checkbox_use_advanced_deform;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_checkbox_rollon, "checkbox_rollon");
	MyGUI::Button* m_checkbox_rollon;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_dry_mass_doc, "label_dry_mass_doc");
	MyGUI::TextBox* m_label_dry_mass_doc;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_load_mass_doc, "label_load_mass_doc");
	MyGUI::TextBox* m_label_load_mass_doc;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_minimass_doc, "label_minimass_doc");
	MyGUI::TextBox* m_label_minimass_doc;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_checkbox_use_advanced_deform_doc, "label_checkbox_use_advanced_deform_doc");
	MyGUI::TextBox* m_label_checkbox_use_advanced_deform_doc;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_rollon_doc, "label_rollon_doc");
	MyGUI::TextBox* m_label_rollon_doc;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_rig_properties_gui_panel, "rig_properties_gui_panel");
	MyGUI::TabItem* m_rig_properties_gui_panel;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_help_panel_mat_name, "label_help_panel_mat_name");
	MyGUI::TextBox* m_label_help_panel_mat_name;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_guisettings_tacho, "label_guisettings_tacho");
	MyGUI::TextBox* m_label_guisettings_tacho;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_guisettings_speedo, "label_guisettings_speedo");
	MyGUI::TextBox* m_label_guisettings_speedo;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_guisettings_speedo_max, "label_guisettings_speedo_max");
	MyGUI::TextBox* m_label_guisettings_speedo_max;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_checkbox_guisettings_speedo_use_engine_max_rpm, "checkbox_guisettings_speedo_use_engine_max_rpm");
	MyGUI::Button* m_checkbox_guisettings_speedo_use_engine_max_rpm;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_guisettings_help_mat, "label_guisettings_help_mat");
	MyGUI::TextBox* m_label_guisettings_help_mat;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_guisettings_minimap, "label_guisettings_minimap");
	MyGUI::TextBox* m_label_guisettings_minimap;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_radio_guisettings_minimap_off, "radio_guisettings_minimap_off");
	MyGUI::Button* m_radio_guisettings_minimap_off;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_radio_guisettings_minimap_simple, "radio_guisettings_minimap_simple");
	MyGUI::Button* m_radio_guisettings_minimap_simple;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_radio_guisettings_minimap_zoom, "radio_guisettings_minimap_zoom");
	MyGUI::Button* m_radio_guisettings_minimap_zoom;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_guisettings_dashboard_layout, "label_guisettings_dashboard_layout");
	MyGUI::TextBox* m_label_guisettings_dashboard_layout;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_guisettings_rtt_dashboard_layout, "label_guisettings_rtt_dashboard_layout");
	MyGUI::TextBox* m_label_guisettings_rtt_dashboard_layout;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_help_panel_mat_name_doc, "label_help_panel_mat_name_doc");
	MyGUI::TextBox* m_label_help_panel_mat_name_doc;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_guisettings_tacho_doc, "label_guisettings_tacho_doc");
	MyGUI::TextBox* m_label_guisettings_tacho_doc;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_guisettings_speedo_doc, "label_guisettings_speedo_doc");
	MyGUI::TextBox* m_label_guisettings_speedo_doc;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_guisettings_rtt_dashboard_layout_doc, "label_guisettings_rtt_dashboard_layout_doc");
	MyGUI::TextBox* m_label_guisettings_rtt_dashboard_layout_doc;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_guisettings_speedo_max_doc, "label_guisettings_speedo_max_doc");
	MyGUI::TextBox* m_label_guisettings_speedo_max_doc;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_guisettings_minimap_doc, "label_guisettings_minimap_doc");
	MyGUI::TextBox* m_label_guisettings_minimap_doc;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_guisettings_dashboard_layout_doc, "label_guisettings_dashboard_layout_doc");
	MyGUI::TextBox* m_label_guisettings_dashboard_layout_doc;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_checkbox_guisettings_speedo_usemaxrpm_doc, "checkbox_guisettings_speedo_usemaxrpm_doc");
	MyGUI::TextBox* m_checkbox_guisettings_speedo_usemaxrpm_doc;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_guisettings_help_mat_doc, "label_guisettings_help_mat_doc");
	MyGUI::TextBox* m_label_guisettings_help_mat_doc;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_editbox_help_panel_mat_name, "editbox_help_panel_mat_name");
	MyGUI::EditBox* m_editbox_help_panel_mat_name;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_editbox_guisettings_tacho, "editbox_guisettings_tacho");
	MyGUI::EditBox* m_editbox_guisettings_tacho;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_editbox_guisettings_speedo, "editbox_guisettings_speedo");
	MyGUI::EditBox* m_editbox_guisettings_speedo;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_editbox_guisettings_speedo_max, "editbox_guisettings_speedo_max");
	MyGUI::EditBox* m_editbox_guisettings_speedo_max;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_label_guisettings_speedo_max_units, "label_guisettings_speedo_max_units");
	MyGUI::TextBox* m_label_guisettings_speedo_max_units;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_editbox_guisettings_help_mat, "editbox_guisettings_help_mat");
	MyGUI::EditBox* m_editbox_guisettings_help_mat;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_editbox_guisettings_dashboard_layout, "editbox_guisettings_dashboard_layout");
	MyGUI::EditBox* m_editbox_guisettings_dashboard_layout;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_editbox_guisettings_rtt_dashboard_layout, "editbox_guisettings_rtt_dashboard_layout");
	MyGUI::EditBox* m_editbox_guisettings_rtt_dashboard_layout;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_button_cancel, "button_cancel");
	MyGUI::Button* m_button_cancel;

	ATTRIBUTE_FIELD_WIDGET_NAME(RigEditorRigPropertiesWindowLayout, m_button_save, "button_save");
	MyGUI::Button* m_button_save;

	//%LE Widget_Declaration list end
};

} // namespace GUI

} // namespace RoR

