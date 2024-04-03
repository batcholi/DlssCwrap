/*
 * DlssCwrap for Windows
 * This is a very simple C wrapper around a few functions from the official nvngx_dlss.lib
 * The reason we need this is because MinGW does not like the official library that was compiled using MSVC with C++ exports
 * Hence, here we re-export these functions as C and compile it using MSVC, then we can simply statically link to it.
 * The Linux version does not need this and we can link normally with libnvsdk_ngx.a and implement this file directly
 */

#ifdef _MSC_VER
	#define DLSSCWRAP_FUNC extern "C" __declspec(dllexport)
#endif
#include "DlssCwrap.h"

NVSDK_NGX_Result DlssCwrap__NVSDK_NGX_VULKAN_Init(
	unsigned long long InApplicationId,
	const wchar_t* InApplicationDataPath,
	VkInstance InInstance,
	VkPhysicalDevice InPD,
	VkDevice InDevice,
	PFN_vkGetInstanceProcAddr InGIPA,
	PFN_vkGetDeviceProcAddr InGDPA) {
	return NVSDK_NGX_VULKAN_Init(
		InApplicationId,
		InApplicationDataPath,
		InInstance,
		InPD,
		InDevice,
		InGIPA,
		InGDPA,
		nullptr,
		NVSDK_NGX_Version_API);
}

NVSDK_NGX_Result DlssCwrap__NVSDK_NGX_VULKAN_Init_with_ProjectID(
	const char* InProjectId,
	NVSDK_NGX_EngineType InEngineType,
	const char* InEngineVersion,
	const wchar_t* InApplicationDataPath,
	VkInstance InInstance,
	VkPhysicalDevice InPD,
	VkDevice InDevice,
	PFN_vkGetInstanceProcAddr InGIPA,
	PFN_vkGetDeviceProcAddr InGDPA) {
	return NVSDK_NGX_VULKAN_Init_with_ProjectID(
		InProjectId,
		InEngineType,
		InEngineVersion,
		InApplicationDataPath,
		InInstance,
		InPD,
		InDevice,
		InGIPA,
		InGDPA,
		nullptr,
		NVSDK_NGX_Version_API);
}

NVSDK_NGX_Result DlssCwrap__NVSDK_NGX_VULKAN_GetCapabilityParameters(
	NVSDK_NGX_Parameter** OutParameters) {
	return NVSDK_NGX_VULKAN_GetCapabilityParameters(OutParameters);
}

NVSDK_NGX_Result DlssCwrap__NGX_VULKAN_CREATE_DLSS_EXT(
	VkCommandBuffer InCmdList,
	unsigned int InCreationNodeMask,
	unsigned int InVisibilityNodeMask,
	NVSDK_NGX_Handle** ppOutHandle,
	NVSDK_NGX_Parameter* pInParams,
	NVSDK_NGX_DLSS_Create_Params* pInDlssCreateParams) {
	return NGX_VULKAN_CREATE_DLSS_EXT(
		InCmdList,
		InCreationNodeMask,
		InVisibilityNodeMask,
		ppOutHandle,
		pInParams,
		pInDlssCreateParams);
}

NVSDK_NGX_Result DlssCwrap__NGX_VULKAN_CREATE_DLSS_EXT1(
	VkDevice InDevice,
	VkCommandBuffer InCmdList,
	unsigned int InCreationNodeMask,
	unsigned int InVisibilityNodeMask,
	NVSDK_NGX_Handle** ppOutHandle,
	NVSDK_NGX_Parameter* pInParams,
	NVSDK_NGX_DLSS_Create_Params* pInDlssCreateParams) {
	return NGX_VULKAN_CREATE_DLSS_EXT1(
		InDevice,
		InCmdList,
		InCreationNodeMask,
		InVisibilityNodeMask,
		ppOutHandle,
		pInParams,
		pInDlssCreateParams);
}

NVSDK_NGX_Result DlssCwrap__NVSDK_NGX_VULKAN_CreateFeature(VkCommandBuffer InCmdBuffer, NVSDK_NGX_Feature InFeatureID, NVSDK_NGX_Parameter* InParameters, NVSDK_NGX_Handle** OutHandle) {
	return NVSDK_NGX_VULKAN_CreateFeature(InCmdBuffer, InFeatureID, InParameters, OutHandle);
}
NVSDK_NGX_Result DlssCwrap__NVSDK_NGX_VULKAN_CreateFeature1(VkDevice InDevice, VkCommandBuffer InCmdList, NVSDK_NGX_Feature InFeatureID, NVSDK_NGX_Parameter* InParameters, NVSDK_NGX_Handle** OutHandle) {
	return NVSDK_NGX_VULKAN_CreateFeature1(InDevice, InCmdList, InFeatureID, InParameters, OutHandle);
}

NVSDK_NGX_Result DlssCwrap__NGX_DLSS_GET_OPTIMAL_SETTINGS(
	NVSDK_NGX_Parameter* pInParams,
	unsigned int InUserSelectedWidth,
	unsigned int InUserSelectedHeight,
	NVSDK_NGX_PerfQuality_Value InPerfQualityValue,
	unsigned int* pOutRenderOptimalWidth,
	unsigned int* pOutRenderOptimalHeight,
	unsigned int* pOutRenderMaxWidth,
	unsigned int* pOutRenderMaxHeight,
	unsigned int* pOutRenderMinWidth,
	unsigned int* pOutRenderMinHeight,
	float* pOutSharpness) {
	return NGX_DLSS_GET_OPTIMAL_SETTINGS(
		pInParams,
		InUserSelectedWidth,
		InUserSelectedHeight,
		InPerfQualityValue,
		pOutRenderOptimalWidth,
		pOutRenderOptimalHeight,
		pOutRenderMaxWidth,
		pOutRenderMaxHeight,
		pOutRenderMinWidth,
		pOutRenderMinHeight,
		pOutSharpness);
}

NVSDK_NGX_Resource_VK DlssCwrap__NVSDK_NGX_Create_ImageView_Resource_VK(
	VkImageView imageView,
	VkImage image,
	VkImageSubresourceRange subresourceRange,
	VkFormat format,
	unsigned int width,
	unsigned int height,
	bool readWrite) {
	return NVSDK_NGX_Create_ImageView_Resource_VK(
		imageView,
		image,
		subresourceRange,
		format,
		width,
		height,
		readWrite);
}

NVSDK_NGX_Result DlssCwrap__NGX_VULKAN_EVALUATE_DLSS_EXT(
	VkCommandBuffer InCmdList,
	NVSDK_NGX_Handle* pInHandle,
	NVSDK_NGX_Parameter* pInParams,
	NVSDK_NGX_VK_DLSS_Eval_Params* pInDlssEvalParams) {
	return NGX_VULKAN_EVALUATE_DLSS_EXT(
		InCmdList,
		pInHandle,
		pInParams,
		pInDlssEvalParams);
}

NVSDK_NGX_Result DlssCwrap__NVSDK_NGX_VULKAN_ReleaseFeature(
	NVSDK_NGX_Handle* InHandle) {
	return NVSDK_NGX_VULKAN_ReleaseFeature(
		InHandle);
}

NVSDK_NGX_Result DlssCwrap__NVSDK_NGX_VULKAN_DestroyParameters(
	NVSDK_NGX_Parameter* InParameters) {
	return NVSDK_NGX_VULKAN_DestroyParameters(
		InParameters);
}

NVSDK_NGX_Result DlssCwrap__NVSDK_NGX_VULKAN_Shutdown() {
	return NVSDK_NGX_VULKAN_Shutdown1(nullptr);
}

