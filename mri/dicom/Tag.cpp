
#include "pydicomlib.hpp"
using namespace boost::python;
using namespace dicom;

void AppendTagDefinitions()
{
	enum_<Tag>("Tag")
		.value("NULL",TAG_NULL)
		.value("AFF_SOP_CLASS_UID",TAG_AFF_SOP_CLASS_UID)
		.value("REQ_SOP_CLASS_UID",TAG_REQ_SOP_CLASS_UID)
		.value("CMD_FIELD",TAG_CMD_FIELD)
		.value("MSG_ID",TAG_MSG_ID)
		.value("MSG_ID_RSP",TAG_MSG_ID_RSP)
		.value("MOVE_DEST",TAG_MOVE_DEST)
		.value("PRIORITY",TAG_PRIORITY)
		.value("DATA_SET_TYPE",TAG_DATA_SET_TYPE)
		.value("STATUS",TAG_STATUS)
		.value("OFFEND_ELEM",TAG_OFFEND_ELEM)
		.value("ERR_COMMENT",TAG_ERR_COMMENT)
		.value("ERR_ID",TAG_ERR_ID)
		.value("AFF_SOP_INST_UID",TAG_AFF_SOP_INST_UID)
		.value("REQ_SOP_INST_UID",TAG_REQ_SOP_INST_UID)
		.value("EVENT_TYPE_ID",TAG_EVENT_TYPE_ID)
		.value("ATTR_ID_LIST",TAG_ATTR_ID_LIST)
		.value("ACTION_TYPE_ID",TAG_ACTION_TYPE_ID)
		.value("NUM_REMAIN_SUBOP",TAG_NUM_REMAIN_SUBOP)
		.value("NUM_COMPL_SUBOP",TAG_NUM_COMPL_SUBOP)
		.value("NUM_FAIL_SUBOP",TAG_NUM_FAIL_SUBOP)
		.value("NUM_WARN_SUBOP",TAG_NUM_WARN_SUBOP)
		.value("MOVE_ORIG_AET",TAG_MOVE_ORIG_AET)
		.value("MOVE_ORIG_MSG_ID",TAG_MOVE_ORIG_MSG_ID)
		.value("FILE_INFO_GR_LEN",TAG_FILE_INFO_GR_LEN)
		.value("FILE_INFO_VERS",TAG_FILE_INFO_VERS)
		.value("MEDIA_SOP_CLASS_UID",TAG_MEDIA_SOP_CLASS_UID)
		.value("MEDIA_SOP_INST_UID",TAG_MEDIA_SOP_INST_UID)
		.value("TRANSFER_SYNTAX_UID",TAG_TRANSFER_SYNTAX_UID)
		.value("IMPL_CLASS_UID",TAG_IMPL_CLASS_UID)
		.value("IMPL_VERS_NAME",TAG_IMPL_VERS_NAME)
		.value("SRC_AET",TAG_SRC_AET)
		.value("PRIV_INFO_CREATOR_UID",TAG_PRIV_INFO_CREATOR_UID)
		.value("PRIV_INFO",TAG_PRIV_INFO)
		.value("FILE_SET_ID",TAG_FILE_SET_ID)
		.value("DESC_FILE_ID",TAG_DESC_FILE_ID)
		.value("CHAR_SET_DESC_FILE",TAG_CHAR_SET_DESC_FILE)
		.value("OFFSET_FIRST_REC",TAG_OFFSET_FIRST_REC)
		.value("OFFSET_LAST_REC",TAG_OFFSET_LAST_REC)
		.value("FILE_SET_CONS",TAG_FILE_SET_CONS)
		.value("REC_SEQ",TAG_REC_SEQ)
		.value("OFFSET_NEXT_REC",TAG_OFFSET_NEXT_REC)
		.value("REC_IN_USE",TAG_REC_IN_USE)
		.value("OFFSET_REF_LOWER",TAG_OFFSET_REF_LOWER)
		.value("REC_TYPE",TAG_REC_TYPE)
		.value("PRIV_REC_UID",TAG_PRIV_REC_UID)
		.value("REF_FILE_ID",TAG_REF_FILE_ID)
		.value("MRDR_OFFSET",TAG_MRDR_OFFSET)
		.value("REF_FILE_SOP_CLASS_UID",TAG_REF_FILE_SOP_CLASS_UID)
		.value("REF_FILE_SOP_INST_UID",TAG_REF_FILE_SOP_INST_UID)
		.value("REF_FILE_TS_UID",TAG_REF_FILE_TS_UID)
		.value("NUM_OF_REF",TAG_NUM_OF_REF)
		.value("CHAR_SET",TAG_CHAR_SET)
		.value("IMAGE_TYPE",TAG_IMAGE_TYPE)
		.value("INST_CREATE_DATE",TAG_INST_CREATE_DATE)
		.value("INST_CREATE_TIME",TAG_INST_CREATE_TIME)
		.value("INST_CREATOR_UID",TAG_INST_CREATOR_UID)
		.value("SOP_CLASS_UID",TAG_SOP_CLASS_UID)
		.value("SOP_INST_UID",TAG_SOP_INST_UID)
		.value("STUDY_DATE",TAG_STUDY_DATE)
		.value("SERIES_DATE",TAG_SERIES_DATE)
		.value("ACQUISITION_DATE",TAG_ACQUISITION_DATE)
		.value("IMAGE_DATE",TAG_IMAGE_DATE)
		.value("STUDY_TIME",TAG_STUDY_TIME)
		.value("SERIES_TIME",TAG_SERIES_TIME)
		.value("ACQUITION_TIME",TAG_ACQUITION_TIME)
		.value("IMAGE_TIME",TAG_IMAGE_TIME)
		.value("ACCESS_NO",TAG_ACCESS_NO)
		.value("QR_LEVEL",TAG_QR_LEVEL)
		.value("RETR_AET",TAG_RETR_AET)
		.value("MODALITY",TAG_MODALITY)
		.value("CONVERSION_TYPE",TAG_CONVERSION_TYPE)
		.value("PRESENTATION_TYPE",TAG_PRESENTATION_TYPE)
		.value("MANUFACTOR",TAG_MANUFACTOR)
		.value("INSTITUT_NAME",TAG_INSTITUT_NAME)
		.value("INSTITUT_ADDRESS",TAG_INSTITUT_ADDRESS)
		.value("REF_PHYS_NAME",TAG_REF_PHYS_NAME)
		.value("REF_PHYS_ADDR",TAG_REF_PHYS_ADDR)
		.value("REF_PHYS_TEL",TAG_REF_PHYS_TEL)
		.value("CODE_VALUE",TAG_CODE_VALUE)
		.value("CODING_SCHEME_DESIGNER",TAG_CODING_SCHEME_DESIGNER)
		.value("CODE_MEANING",TAG_CODE_MEANING)
		.value("STATION_NAME",TAG_STATION_NAME)
		.value("STUDY_DESC",TAG_STUDY_DESC)
		.value("PROC_CODE_SEQ",TAG_PROC_CODE_SEQ)
		.value("SERIES_DESC",TAG_SERIES_DESC)
		.value("INSTITUT_DEPT_NAME",TAG_INSTITUT_DEPT_NAME)
		.value("PERF_PHYS_NAME",TAG_PERF_PHYS_NAME)
		.value("READ_PHYS_NAME",TAG_READ_PHYS_NAME)
		.value("OPERATOR_NAME",TAG_OPERATOR_NAME)
		.value("ADMIT_DIAG_DESC",TAG_ADMIT_DIAG_DESC)
		.value("MANFAC_MODEL_NAME",TAG_MANFAC_MODEL_NAME)
		.value("REF_STUDY_SEQ",TAG_REF_STUDY_SEQ)
		.value("REF_STUDY_COMPONENT_SEQ",TAG_REF_STUDY_COMPONENT_SEQ)
		.value("REF_PAT_SEQ",TAG_REF_PAT_SEQ)
		.value("REF_IMAGE_SEQ",TAG_REF_IMAGE_SEQ)
		.value("REF_SOP_CLASS_UID",TAG_REF_SOP_CLASS_UID)
		.value("REF_SOP_INST_UID",TAG_REF_SOP_INST_UID)
		.value("REF_SOP_SEQ",TAG_REF_SOP_SEQ)
		.value("PAT_NAME",TAG_PAT_NAME)
		.value("PAT_ID",TAG_PAT_ID)
		.value("PAT_BIRTH_DATE",TAG_PAT_BIRTH_DATE)
		.value("PAT_SEX",TAG_PAT_SEX)
		.value("OTHER_PAT_ID",TAG_OTHER_PAT_ID)
		.value("PAT_AGE",TAG_PAT_AGE)
		.value("PAT_SIZE",TAG_PAT_SIZE)
		.value("PAT_WEIGHT",TAG_PAT_WEIGHT)
		.value("PAT_ADDR",TAG_PAT_ADDR)
		.value("PAT_TEL",TAG_PAT_TEL)
		.value("OCCUPATION",TAG_OCCUPATION)
		.value("ADDITIONAL_PT_HISTORY",TAG_ADDITIONAL_PT_HISTORY)
		.value("PAT_COMMENT",TAG_PAT_COMMENT)
		.value("BODY_PART_EXAMINED",TAG_BODY_PART_EXAMINED)
		.value("SLANT_ANGLE",TAG_SLANT_ANGLE)
		.value("KVP",TAG_KVP)
		.value("DEVICE_SERIAL_NUMBER",TAG_DEVICE_SERIAL_NUMBER)
		.value("SOFTWARE_VERSION",TAG_SOFTWARE_VERSION)
		.value("SECONDARY_CAPTURE_DATE",TAG_SECONDARY_CAPTURE_DATE)
		.value("HARDCOPY_DEVICE_MANUFACTURER",TAG_HARDCOPY_DEVICE_MANUFACTURER)
		.value("SECONDARY_CAPTURE_DEVICE_MODEL_NAME",TAG_SECONDARY_CAPTURE_DEVICE_MODEL_NAME)
		.value("SECONDARY_CAPTURE_DEVICE_SOFTWARE_VERSION",TAG_SECONDARY_CAPTURE_DEVICE_SOFTWARE_VERSION)
		.value("VIDEO_IMAGE_FORMAT_ACQUIRED",TAG_VIDEO_IMAGE_FORMAT_ACQUIRED)
		.value("PROT_NAME",TAG_PROT_NAME)
		.value("EXPOSURE_MAS",TAG_EXPOSURE_MAS)
		.value("IMGR_PIXEL_SPACING",TAG_IMGR_PIXEL_SPACING)
		.value("ANODE_MATERIAL",TAG_ANODE_MATERIAL)
		.value("SENSITIVITY",TAG_SENSITIVITY)
		.value("BODY_PART_THICKNESS",TAG_BODY_PART_THICKNESS)
		.value("COMPRESSION_FORCE",TAG_COMPRESSION_FORCE)
		.value("ESTIMATED_RADIOGRAPHIC_MAGNIFICATION_FACTOR",TAG_ESTIMATED_RADIOGRAPHIC_MAGNIFICATION_FACTOR)
		.value("FOCAL_SPOT",TAG_FOCAL_SPOT)
		.value("COLLIMATOR_LEFT_EDGE",TAG_COLLIMATOR_LEFT_EDGE)
		.value("COLLIMATOR_RIGHT_EDGE",TAG_COLLIMATOR_RIGHT_EDGE)
		.value("COLLIMATOR_UPPER_EDGE",TAG_COLLIMATOR_UPPER_EDGE)
		.value("COLLIMATOR_LOWER_EDGE",TAG_COLLIMATOR_LOWER_EDGE)
		.value("VIEW_POSITION",TAG_VIEW_POSITION)
		.value("FILTER_MATERIAL",TAG_FILTER_MATERIAL)
		.value("EXPOSURE_CONTROL_MODE",TAG_EXPOSURE_CONTROL_MODE)
		.value("EXPOSURE_CONTROL_MODE_DESC",TAG_EXPOSURE_CONTROL_MODE_DESC)
		.value("STUDY_INST_UID",TAG_STUDY_INST_UID)
		.value("SERIES_INST_UID",TAG_SERIES_INST_UID)
		.value("STUDY_ID",TAG_STUDY_ID)
		.value("SERIES_NO",TAG_SERIES_NO)
		.value("ACQUISITION_NO",TAG_ACQUISITION_NO)
		.value("IMAGE_NO",TAG_IMAGE_NO)
		.value("PATIENT_ORIENTATION",TAG_PATIENT_ORIENTATION)
		.value("OVERLAY_NO",TAG_OVERLAY_NO)
		.value("CURVE_NO",TAG_CURVE_NO)
		.value("LUT_NO",TAG_LUT_NO)
		.value("IMAGE_ORIENTATION",TAG_IMAGE_ORIENTATION)
		.value("LATERALITY",TAG_LATERALITY)
		.value("IMAGE_LATERALITY",TAG_IMAGE_LATERALITY)
		.value("NO_PAT_REL_STUDIES",TAG_NO_PAT_REL_STUDIES)
		.value("NO_PAT_REL_SERIES",TAG_NO_PAT_REL_SERIES)
		.value("NO_PAT_REL_IMAGES",TAG_NO_PAT_REL_IMAGES)
		.value("NO_STUDY_REL_SERIES",TAG_NO_STUDY_REL_SERIES)
		.value("NO_STUDY_REL_IMAGES",TAG_NO_STUDY_REL_IMAGES)
		.value("NO_SERIES_REL_IMAGES",TAG_NO_SERIES_REL_IMAGES)
		.value("SAMPLES_PER_PX",TAG_SAMPLES_PER_PX)
		.value("PHOTOMETRIC",TAG_PHOTOMETRIC)
		.value("ROWS",TAG_ROWS)
		.value("COLUMNS",TAG_COLUMNS)
		.value("PLANES",TAG_PLANES)
		.value("PIXEL_SPACING",TAG_PIXEL_SPACING)
		.value("BITS_ALLOC",TAG_BITS_ALLOC)
		.value("BITS_STORED",TAG_BITS_STORED)
		.value("HIGH_BIT",TAG_HIGH_BIT)
		.value("PX_REPRESENT",TAG_PX_REPRESENT)
		.value("PXL_INTENSITY_RELATIONSHIP",TAG_PXL_INTENSITY_RELATIONSHIP)
		.value("PXL_INTENSITY_SIGN",TAG_PXL_INTENSITY_SIGN)
		.value("WINDOW_CENTER",TAG_WINDOW_CENTER)
		.value("WINDOW_WIDTH",TAG_WINDOW_WIDTH)
		.value("RESCALE_INTERCEPT",TAG_RESCALE_INTERCEPT)
		.value("RESCALE_SLOPE",TAG_RESCALE_SLOPE)
		.value("RESCALE_TYPE",TAG_RESCALE_TYPE)
		.value("RED_PAL_LUT",TAG_RED_PAL_LUT)
		.value("GREEN_PAL_LUT",TAG_GREEN_PAL_LUT)
		.value("BLUE_PAL_LUT",TAG_BLUE_PAL_LUT)
		.value("SEG_RED_PAL_LUT",TAG_SEG_RED_PAL_LUT)
		.value("SEG_GREEN_PAL_LUT",TAG_SEG_GREEN_PAL_LUT)
		.value("SEG_BLUE_PAL_LUT",TAG_SEG_BLUE_PAL_LUT)
		.value("ICON_IMAGE_SEQ",TAG_ICON_IMAGE_SEQ)
		.value("TOPIC_TITLE",TAG_TOPIC_TITLE)
		.value("TOPIC_SUBJECT",TAG_TOPIC_SUBJECT)
		.value("TOPIC_AUTHOR",TAG_TOPIC_AUTHOR)
		.value("TOPIC_KEYWORDS",TAG_TOPIC_KEYWORDS)
		.value("STUDY_STATUS_ID",TAG_STUDY_STATUS_ID)
		.value("REQ_PHYS",TAG_REQ_PHYS)
		.value("REQ_SERVICE",TAG_REQ_SERVICE)
		.value("REQ_PROC_DESC",TAG_REQ_PROC_DESC)
		.value("REQ_CONTRAST_AGENT",TAG_REQ_CONTRAST_AGENT)
		.value("ADMISSION_ID",TAG_ADMISSION_ID)
		.value("ROUTE_OF_ADMISS",TAG_ROUTE_OF_ADMISS)
		.value("ADMIT_DATE",TAG_ADMIT_DATE)
		.value("SPS_STATION_AET",TAG_SPS_STATION_AET)
		.value("SPS_START_DATE",TAG_SPS_START_DATE)
		.value("SPS_START_TIME",TAG_SPS_START_TIME)
		.value("SPS_END_DATE",TAG_SPS_END_DATE)
		.value("SPS_END_TIME",TAG_SPS_END_TIME)
		.value("SPS_PERF_PHYS_NAME",TAG_SPS_PERF_PHYS_NAME)
		.value("SPS_DESC",TAG_SPS_DESC)
		.value("SPS_ACTION_SEQ",TAG_SPS_ACTION_SEQ)
		.value("SPS_ID",TAG_SPS_ID)
		.value("SPS_STATION_NAME",TAG_SPS_STATION_NAME)
		.value("SPS_LOCATION",TAG_SPS_LOCATION)
		.value("PRE_MEDICATION",TAG_PRE_MEDICATION)
		.value("SPS_STATUS",TAG_SPS_STATUS)
		.value("SPS_SEQ",TAG_SPS_SEQ)
		.value("REF_STANDALONE_SOP_INST_SEQ",TAG_REF_STANDALONE_SOP_INST_SEQ)
		.value("PERF_STATION_AET",TAG_PERF_STATION_AET)
		.value("PERF_STATION_NAME",TAG_PERF_STATION_NAME)
		.value("PERF_LOCATION",TAG_PERF_LOCATION)
		.value("PPS_START_DATE",TAG_PPS_START_DATE)
		.value("PPS_START_TIME",TAG_PPS_START_TIME)
		.value("PPS_END_DATE",TAG_PPS_END_DATE)
		.value("PPS_END_TIME",TAG_PPS_END_TIME)
		.value("PPS_STATUS",TAG_PPS_STATUS)
		.value("PPS_ID",TAG_PPS_ID)
		.value("PPS_DESC",TAG_PPS_DESC)
		.value("PERF_TYPE_DESC",TAG_PERF_TYPE_DESC)
		.value("PERF_ACTION_SEQ",TAG_PERF_ACTION_SEQ)
		.value("SPS_ATTRIB_SEQ",TAG_SPS_ATTRIB_SEQ)
		.value("REQ_ATTRIB_SEQ",TAG_REQ_ATTRIB_SEQ)
		.value("COMMENT_PPS",TAG_COMMENT_PPS)
		.value("QUANTITY_SEQ",TAG_QUANTITY_SEQ)
		.value("QUANTITY",TAG_QUANTITY)
		.value("MEASURING_UNITS_SEQ",TAG_MEASURING_UNITS_SEQ)
		.value("BILLING_ITEM_SEQ",TAG_BILLING_ITEM_SEQ)
		.value("TOT_TIME_FLUOROS",TAG_TOT_TIME_FLUOROS)
		.value("TOT_NUM_EXPOS",TAG_TOT_NUM_EXPOS)
		.value("ENTRANCE_DOSE",TAG_ENTRANCE_DOSE)
		.value("EXPOSED_AREA",TAG_EXPOSED_AREA)
		.value("DISTANCE_SOURCE_ENTRANCE",TAG_DISTANCE_SOURCE_ENTRANCE)
		.value("COMMENT_RADIATION_DOSE",TAG_COMMENT_RADIATION_DOSE)
		.value("BILLING_PPS_SEQ",TAG_BILLING_PPS_SEQ)
		.value("FILM_CONSUM_SEQ",TAG_FILM_CONSUM_SEQ)
		.value("BILLING_SUPPL_DEVICES_SEQ",TAG_BILLING_SUPPL_DEVICES_SEQ)
		.value("REF_PPS_SEQ",TAG_REF_PPS_SEQ)
		.value("PERF_SERIES_SEQ",TAG_PERF_SERIES_SEQ)
		.value("COMMENTS_ON_SPS",TAG_COMMENTS_ON_SPS)
		.value("REQ_PROC_ID",TAG_REQ_PROC_ID)
		.value("REASON_REQ_PROC",TAG_REASON_REQ_PROC)
		.value("REQ_PROC_PRIORITY",TAG_REQ_PROC_PRIORITY)
		.value("PAT_TRANS_ARRANGE",TAG_PAT_TRANS_ARRANGE)
		.value("REQ_PROCEDURE_LOC",TAG_REQ_PROCEDURE_LOC)
		.value("PLACER_ORDER_NUM_PROC",TAG_PLACER_ORDER_NUM_PROC)
		.value("FILLER_ORDER_NUM_PROC",TAG_FILLER_ORDER_NUM_PROC)
		.value("CONFID_CODE",TAG_CONFID_CODE)
		.value("REPORT_PRIORITY",TAG_REPORT_PRIORITY)
		.value("RECIPIENTS_OF_RESULT",TAG_RECIPIENTS_OF_RESULT)
		.value("REQ_PROC_COMMENT",TAG_REQ_PROC_COMMENT)
		.value("REASON_ISRQ",TAG_REASON_ISRQ)
		.value("ISSUE_DATE_ISRQ",TAG_ISSUE_DATE_ISRQ)
		.value("ISSUE_TIME_ISRQ",TAG_ISSUE_TIME_ISRQ)
		.value("PLACER_ORDER_NO_ISRQ",TAG_PLACER_ORDER_NO_ISRQ)
		.value("FILLER_ORDER_NO_ISRQ",TAG_FILLER_ORDER_NO_ISRQ)
		.value("ORDER_ENTEREDBY",TAG_ORDER_ENTEREDBY)
		.value("ORDER_ENTERER",TAG_ORDER_ENTERER)
		.value("ORDER_CALLBACK_TEL",TAG_ORDER_CALLBACK_TEL)
		.value("ISRQ_COMMENTS",TAG_ISRQ_COMMENTS)
		.value("CONFID_CONSTRAIN_PAT_DESC",TAG_CONFID_CONSTRAIN_PAT_DESC)
		.value("RELATIONSHIP_TYPE",TAG_RELATIONSHIP_TYPE)
		.value("VERIFYING_ORGANIZATION",TAG_VERIFYING_ORGANIZATION)
		.value("VERIFICATION_DATE_TIME",TAG_VERIFICATION_DATE_TIME)
		.value("OBSERVATION_DATE_TIME",TAG_OBSERVATION_DATE_TIME)
		.value("VALUE_TYPE",TAG_VALUE_TYPE)
		.value("CONCEPT_NAME_CODE_SEQ",TAG_CONCEPT_NAME_CODE_SEQ)
		.value("CONTINUITY_OF_CONTENT",TAG_CONTINUITY_OF_CONTENT)
		.value("VERIFYING_OBSERVER_SEQ",TAG_VERIFYING_OBSERVER_SEQ)
		.value("VERIFYING_OBSERVER_NAME",TAG_VERIFYING_OBSERVER_NAME)
		.value("VERF_OBSERVER_ID_CODE_SEQ",TAG_VERF_OBSERVER_ID_CODE_SEQ)
		.value("DATE_TIME",TAG_DATE_TIME)
		.value("MEASURED_VALUE_SEQ",TAG_MEASURED_VALUE_SEQ)
		.value("PREDECESSOR_DOCUMENTS_SEQ",TAG_PREDECESSOR_DOCUMENTS_SEQ)
		.value("REFERENCED_REQUEST_SEQ",TAG_REFERENCED_REQUEST_SEQ)
		.value("PERFORMED_PROCEDURE_CODE_SEQ",TAG_PERFORMED_PROCEDURE_CODE_SEQ)
		.value("REQEUSTED_PROCEDURE_EVIDENCE_SEQ",TAG_REQEUSTED_PROCEDURE_EVIDENCE_SEQ)
		.value("PERTINENT_OTHER_EVIDENCE_SEQ",TAG_PERTINENT_OTHER_EVIDENCE_SEQ)
		.value("COMPLETION_FLAG",TAG_COMPLETION_FLAG)
		.value("COMPLETION_FLAG_DESC",TAG_COMPLETION_FLAG_DESC)
		.value("VERIFICATION_FLAG",TAG_VERIFICATION_FLAG)
		.value("CONTENT_TEMPLATE_SEQ",TAG_CONTENT_TEMPLATE_SEQ)
		.value("IDENTICAL_DOCUMENTS_SEQ",TAG_IDENTICAL_DOCUMENTS_SEQ)
		.value("CONTENT_SEQ",TAG_CONTENT_SEQ)
		.value("TEMPLATE_ID",TAG_TEMPLATE_ID)
		.value("TEMPLATE_VERSION",TAG_TEMPLATE_VERSION)
		.value("TEMPLATE_LOCAL_VERSION",TAG_TEMPLATE_LOCAL_VERSION)
		.value("TEMPLATE_EXTENSION_FLAG",TAG_TEMPLATE_EXTENSION_FLAG)
		.value("TEMPLATE_EXTENSION_ORGANIZATION_UID",TAG_TEMPLATE_EXTENSION_ORGANIZATION_UID)
		.value("TEMPLATE_EXTENSION_CREATOR_UID",TAG_TEMPLATE_EXTENSION_CREATOR_UID)
		.value("REFERENCED_CONTENT_ITEM_ID",TAG_REFERENCED_CONTENT_ITEM_ID)
		.value("GRAPHIC_DATA",TAG_GRAPHIC_DATA)
		.value("GRAPHIC_TYPE",TAG_GRAPHIC_TYPE)
		.value("FILM_SESSION_LABEL",TAG_FILM_SESSION_LABEL)
		.value("IMAGE_POS",TAG_IMAGE_POS)
		.value("EXECUTION_STATUS",TAG_EXECUTION_STATUS)
		.value("PRINTER_NAME",TAG_PRINTER_NAME)
		.value("PRINT_QUEUE_ID",TAG_PRINT_QUEUE_ID)
		.value("RESULT_ID",TAG_RESULT_ID)
		.value("INTERPRET_TRANS_DATE",TAG_INTERPRET_TRANS_DATE)
		.value("INTERPRET_AUTHOR",TAG_INTERPRET_AUTHOR)
		.value("INTERPRET_DIAG_DESC",TAG_INTERPRET_DIAG_DESC)
		.value("INTERPRET_DIAG_CODE_SEQ",TAG_INTERPRET_DIAG_CODE_SEQ)
		.value("INTERPRET_ID",TAG_INTERPRET_ID)
		.value("INTERPRET_TYPE_ID",TAG_INTERPRET_TYPE_ID)
		.value("INTERPRET_STATUS_ID",TAG_INTERPRET_STATUS_ID)
		.value("PIXEL_DATA",TAG_PIXEL_DATA)
		.value("DATA_SET_PADDING",TAG_DATA_SET_PADDING)
		.value("ITEM",TAG_ITEM)
		.value("ITEM_DELIM_ITEM",TAG_ITEM_DELIM_ITEM)
		.value("SEQ_DELIM_ITEM",TAG_SEQ_DELIM_ITEM)
		;



		/*
			If we were really clever we would make this the docstring of
			each Tag, but I don't think boost::python supports this.
		*/
		def("GetName",&GetName,		"convert a Tag enum value to a human-readable string");


		def("GetVR",&GetVR,			"Get VR for a given tag");
		def("AddDictionaryEntry",&AddDictionaryEntry);

		def("makeTag",&makeTag);
}
