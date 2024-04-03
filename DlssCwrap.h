#pragma once

#ifndef DLSSCWRAP_FUNC
	#ifdef _WIN32
		#define DLSSCWRAP_FUNC extern "C" __declspec(dllimport)
	#else
		#define DLSSCWRAP_FUNC
	#endif
#endif

#ifdef _MSC_VER
	#ifndef VULKAN_H_
		#define VK_NO_PROTOTYPES
		#include <vulkan.h>
	#endif
#endif

#include <nvsdk_ngx.h>
#include <nvsdk_ngx_helpers.h>
#include <nvsdk_ngx_helpers_vk.h>

DLSSCWRAP_FUNC NVSDK_NGX_Result DlssCwrap__NVSDK_NGX_VULKAN_Init(
	unsigned long long InApplicationId,
	const wchar_t* InApplicationDataPath,
	VkInstance InInstance,
	VkPhysicalDevice InPD,
	VkDevice InDevice,
	PFN_vkGetInstanceProcAddr InGIPA = nullptr,
	PFN_vkGetDeviceProcAddr InGDPA = nullptr);

DLSSCWRAP_FUNC NVSDK_NGX_Result DlssCwrap__NVSDK_NGX_VULKAN_Init_with_ProjectID(
	const char* InProjectId,
	NVSDK_NGX_EngineType InEngineType,
	const char* InEngineVersion,
	const wchar_t* InApplicationDataPath,
	VkInstance InInstance,
	VkPhysicalDevice InPD,
	VkDevice InDevice,
	PFN_vkGetInstanceProcAddr InGIPA = nullptr,
	PFN_vkGetDeviceProcAddr InGDPA = nullptr);

DLSSCWRAP_FUNC NVSDK_NGX_Result DlssCwrap__NVSDK_NGX_VULKAN_GetCapabilityParameters(
	NVSDK_NGX_Parameter** OutParameters);

DLSSCWRAP_FUNC NVSDK_NGX_Result DlssCwrap__NGX_VULKAN_CREATE_DLSS_EXT(
	VkCommandBuffer InCmdList,
	unsigned int InCreationNodeMask,
	unsigned int InVisibilityNodeMask,
	NVSDK_NGX_Handle** ppOutHandle,
	NVSDK_NGX_Parameter* pInParams,
	NVSDK_NGX_DLSS_Create_Params* pInDlssCreateParams);

DLSSCWRAP_FUNC NVSDK_NGX_Result DlssCwrap__NGX_VULKAN_CREATE_DLSS_EXT1(
	VkDevice InDevice,
	VkCommandBuffer InCmdList,
	unsigned int InCreationNodeMask,
	unsigned int InVisibilityNodeMask,
	NVSDK_NGX_Handle** ppOutHandle,
	NVSDK_NGX_Parameter* pInParams,
	NVSDK_NGX_DLSS_Create_Params* pInDlssCreateParams);

DLSSCWRAP_FUNC NVSDK_NGX_Result DlssCwrap__NVSDK_NGX_VULKAN_CreateFeature(VkCommandBuffer InCmdBuffer, NVSDK_NGX_Feature InFeatureID, NVSDK_NGX_Parameter* InParameters, NVSDK_NGX_Handle** OutHandle);
DLSSCWRAP_FUNC NVSDK_NGX_Result DlssCwrap__NVSDK_NGX_VULKAN_CreateFeature1(VkDevice InDevice, VkCommandBuffer InCmdList, NVSDK_NGX_Feature InFeatureID, NVSDK_NGX_Parameter* InParameters, NVSDK_NGX_Handle** OutHandle);

DLSSCWRAP_FUNC NVSDK_NGX_Result DlssCwrap__NGX_DLSS_GET_OPTIMAL_SETTINGS(
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
	float* pOutSharpness);

DLSSCWRAP_FUNC NVSDK_NGX_Resource_VK DlssCwrap__NVSDK_NGX_Create_ImageView_Resource_VK(
	VkImageView imageView,
	VkImage image,
	VkImageSubresourceRange subresourceRange,
	VkFormat format,
	unsigned int width,
	unsigned int height,
	bool readWrite);

DLSSCWRAP_FUNC NVSDK_NGX_Result DlssCwrap__NGX_VULKAN_EVALUATE_DLSS_EXT(
	VkCommandBuffer InCmdList,
	NVSDK_NGX_Handle* pInHandle,
	NVSDK_NGX_Parameter* pInParams,
	NVSDK_NGX_VK_DLSS_Eval_Params* pInDlssEvalParams);

DLSSCWRAP_FUNC NVSDK_NGX_Result DlssCwrap__NVSDK_NGX_VULKAN_ReleaseFeature(
	NVSDK_NGX_Handle* InHandle);

DLSSCWRAP_FUNC NVSDK_NGX_Result DlssCwrap__NVSDK_NGX_VULKAN_DestroyParameters(
	NVSDK_NGX_Parameter* InParameters);

DLSSCWRAP_FUNC NVSDK_NGX_Result DlssCwrap__NVSDK_NGX_VULKAN_Shutdown();

