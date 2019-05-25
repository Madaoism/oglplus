//  File doc/quickbook/oglplus/quickref/enums/limit_query_class.hpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the source 'source/enums/oglplus/limit_query.txt'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright 2010-2019 Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
//[oglplus_enums_limit_query_class
#if !__OGLPLUS_NO_ENUM_VALUE_CLASSES
namespace enums {

template <typename Base, template <__LimitQuery> class Transform>
class __EnumToClass<Base, __LimitQuery, Transform> /*<
Specialization of __EnumToClass for the __LimitQuery enumeration.
>*/
  : public Base {
public:
    EnumToClass();
    EnumToClass(Base&& base);

    Transform<LimitQuery::Max3DTextureSize> Max3DTextureSize;
    Transform<LimitQuery::MaxArrayTextureLayers> MaxArrayTextureLayers;
    Transform<LimitQuery::MaxAtomicCounterBufferBindings>
      MaxAtomicCounterBufferBindings;
    Transform<LimitQuery::MaxAtomicCounterBufferSize>
      MaxAtomicCounterBufferSize;
    Transform<LimitQuery::MaxClipDistances> MaxClipDistances;
    Transform<LimitQuery::MaxCullDistances> MaxCullDistances;
    Transform<LimitQuery::MaxCombinedClipAndCullDistances>
      MaxCombinedClipAndCullDistances;
    Transform<LimitQuery::MaxColorAttachments> MaxColorAttachments;
    Transform<LimitQuery::MaxColorTextureSamples> MaxColorTextureSamples;
    Transform<LimitQuery::MaxCombinedAtomicCounterBuffers>
      MaxCombinedAtomicCounterBuffers;
    Transform<LimitQuery::MaxCombinedAtomicCounters> MaxCombinedAtomicCounters;
    Transform<LimitQuery::MaxCombinedFragmentUniformComponents>
      MaxCombinedFragmentUniformComponents;
    Transform<LimitQuery::MaxCombinedGeometryUniformComponents>
      MaxCombinedGeometryUniformComponents;
    Transform<LimitQuery::MaxCombinedImageUniforms> MaxCombinedImageUniforms;
    Transform<LimitQuery::MaxCombinedImageUnitsAndFragmentOutputs>
      MaxCombinedImageUnitsAndFragmentOutputs;
    Transform<LimitQuery::MaxCombinedTessControlUniformComponents>
      MaxCombinedTessControlUniformComponents;
    Transform<LimitQuery::MaxCombinedTessEvaluationUniformComponents>
      MaxCombinedTessEvaluationUniformComponents;
    Transform<LimitQuery::MaxCombinedTextureImageUnits>
      MaxCombinedTextureImageUnits;
    Transform<LimitQuery::MaxCombinedUniformBlocks> MaxCombinedUniformBlocks;
    Transform<LimitQuery::MaxCombinedVertexUniformComponents>
      MaxCombinedVertexUniformComponents;
    Transform<LimitQuery::MaxCubeMapTextureSize> MaxCubeMapTextureSize;
    Transform<LimitQuery::MaxDepthTextureSamples> MaxDepthTextureSamples;
    Transform<LimitQuery::MaxDrawBuffers> MaxDrawBuffers;
    Transform<LimitQuery::MaxDualSourceDrawBuffers> MaxDualSourceDrawBuffers;
    Transform<LimitQuery::MaxElementsIndices> MaxElementsIndices;
    Transform<LimitQuery::MaxElementsVertices> MaxElementsVertices;
    Transform<LimitQuery::MaxFragmentAtomicCounterBuffers>
      MaxFragmentAtomicCounterBuffers;
    Transform<LimitQuery::MaxFragmentAtomicCounters> MaxFragmentAtomicCounters;
    Transform<LimitQuery::MaxFragmentImageUniforms> MaxFragmentImageUniforms;
    Transform<LimitQuery::MaxFragmentInputComponents>
      MaxFragmentInputComponents;
    Transform<LimitQuery::MaxFragmentInterpolationOffset>
      MaxFragmentInterpolationOffset;
    Transform<LimitQuery::MaxFragmentUniformBlocks> MaxFragmentUniformBlocks;
    Transform<LimitQuery::MaxFragmentUniformComponents>
      MaxFragmentUniformComponents;
    Transform<LimitQuery::MaxFragmentUniformVectors> MaxFragmentUniformVectors;
    Transform<LimitQuery::MaxGeometryAtomicCounterBuffers>
      MaxGeometryAtomicCounterBuffers;
    Transform<LimitQuery::MaxGeometryAtomicCounters> MaxGeometryAtomicCounters;
    Transform<LimitQuery::MaxGeometryImageUniforms> MaxGeometryImageUniforms;
    Transform<LimitQuery::MaxGeometryInputComponents>
      MaxGeometryInputComponents;
    Transform<LimitQuery::MaxGeometryOutputComponents>
      MaxGeometryOutputComponents;
    Transform<LimitQuery::MaxGeometryOutputVertices> MaxGeometryOutputVertices;
    Transform<LimitQuery::MaxGeometryShaderInvocations>
      MaxGeometryShaderInvocations;
    Transform<LimitQuery::MaxGeometryTextureImageUnits>
      MaxGeometryTextureImageUnits;
    Transform<LimitQuery::MaxGeometryTotalOutputComponents>
      MaxGeometryTotalOutputComponents;
    Transform<LimitQuery::MaxGeometryUniformBlocks> MaxGeometryUniformBlocks;
    Transform<LimitQuery::MaxGeometryUniformComponents>
      MaxGeometryUniformComponents;
    Transform<LimitQuery::MaxImageSamples> MaxImageSamples;
    Transform<LimitQuery::MaxImageUnits> MaxImageUnits;
    Transform<LimitQuery::MaxIntegerSamples> MaxIntegerSamples;
    Transform<LimitQuery::MaxPatchVertices> MaxPatchVertices;
    Transform<LimitQuery::MaxProgramTexelOffset> MaxProgramTexelOffset;
    Transform<LimitQuery::MaxProgramTextureGatherOffset>
      MaxProgramTextureGatherOffset;
    Transform<LimitQuery::MaxRectangleTextureSize> MaxRectangleTextureSize;
    Transform<LimitQuery::MaxRenderbufferSize> MaxRenderbufferSize;
    Transform<LimitQuery::MaxSampleMaskWords> MaxSampleMaskWords;
    Transform<LimitQuery::MaxSamples> MaxSamples;
    Transform<LimitQuery::MaxServerWaitTimeout> MaxServerWaitTimeout;
    Transform<LimitQuery::MaxSubroutines> MaxSubroutines;
    Transform<LimitQuery::MaxSubroutineUniformLocations>
      MaxSubroutineUniformLocations;
    Transform<LimitQuery::MaxTessControlAtomicCounterBuffers>
      MaxTessControlAtomicCounterBuffers;
    Transform<LimitQuery::MaxTessControlAtomicCounters>
      MaxTessControlAtomicCounters;
    Transform<LimitQuery::MaxTessControlImageUniforms>
      MaxTessControlImageUniforms;
    Transform<LimitQuery::MaxTessControlInputComponents>
      MaxTessControlInputComponents;
    Transform<LimitQuery::MaxTessControlOutputComponents>
      MaxTessControlOutputComponents;
    Transform<LimitQuery::MaxTessControlTextureImageUnits>
      MaxTessControlTextureImageUnits;
    Transform<LimitQuery::MaxTessControlTotalOutputComponents>
      MaxTessControlTotalOutputComponents;
    Transform<LimitQuery::MaxTessControlUniformBlocks>
      MaxTessControlUniformBlocks;
    Transform<LimitQuery::MaxTessControlUniformComponents>
      MaxTessControlUniformComponents;
    Transform<LimitQuery::MaxTessEvaluationAtomicCounterBuffers>
      MaxTessEvaluationAtomicCounterBuffers;
    Transform<LimitQuery::MaxTessEvaluationAtomicCounters>
      MaxTessEvaluationAtomicCounters;
    Transform<LimitQuery::MaxTessEvaluationImageUniforms>
      MaxTessEvaluationImageUniforms;
    Transform<LimitQuery::MaxTessEvaluationInputComponents>
      MaxTessEvaluationInputComponents;
    Transform<LimitQuery::MaxTessEvaluationOutputComponents>
      MaxTessEvaluationOutputComponents;
    Transform<LimitQuery::MaxTessEvaluationTextureImageUnits>
      MaxTessEvaluationTextureImageUnits;
    Transform<LimitQuery::MaxTessEvaluationUniformBlocks>
      MaxTessEvaluationUniformBlocks;
    Transform<LimitQuery::MaxTessEvaluationUniformComponents>
      MaxTessEvaluationUniformComponents;
    Transform<LimitQuery::MaxTessGenLevel> MaxTessGenLevel;
    Transform<LimitQuery::MaxTessPatchComponents> MaxTessPatchComponents;
    Transform<LimitQuery::MaxTextureBufferSize> MaxTextureBufferSize;
    Transform<LimitQuery::MaxTextureImageUnits> MaxTextureImageUnits;
    Transform<LimitQuery::MaxTextureLodBias> MaxTextureLodBias;
    Transform<LimitQuery::MaxTextureSize> MaxTextureSize;
    Transform<LimitQuery::MaxTransformFeedbackBuffers>
      MaxTransformFeedbackBuffers;
    Transform<LimitQuery::MaxTransformFeedbackInterleavedComponents>
      MaxTransformFeedbackInterleavedComponents;
    Transform<LimitQuery::MaxTransformFeedbackSeparateAttribs>
      MaxTransformFeedbackSeparateAttribs;
    Transform<LimitQuery::MaxTransformFeedbackSeparateComponents>
      MaxTransformFeedbackSeparateComponents;
    Transform<LimitQuery::MaxUniformBlockSize> MaxUniformBlockSize;
    Transform<LimitQuery::MaxUniformBufferBindings> MaxUniformBufferBindings;
    Transform<LimitQuery::MaxVaryingComponents> MaxVaryingComponents;
    Transform<LimitQuery::MaxVaryingVectors> MaxVaryingVectors;
    Transform<LimitQuery::MaxVertexAtomicCounterBuffers>
      MaxVertexAtomicCounterBuffers;
    Transform<LimitQuery::MaxVertexAtomicCounters> MaxVertexAtomicCounters;
    Transform<LimitQuery::MaxVertexAttribs> MaxVertexAttribs;
    Transform<LimitQuery::MaxVertexImageUniforms> MaxVertexImageUniforms;
    Transform<LimitQuery::MaxVertexOutputComponents> MaxVertexOutputComponents;
    Transform<LimitQuery::MaxVertexStreams> MaxVertexStreams;
    Transform<LimitQuery::MaxVertexTextureImageUnits>
      MaxVertexTextureImageUnits;
    Transform<LimitQuery::MaxVertexUniformBlocks> MaxVertexUniformBlocks;
    Transform<LimitQuery::MaxVertexUniformComponents>
      MaxVertexUniformComponents;
    Transform<LimitQuery::MaxVertexUniformVectors> MaxVertexUniformVectors;
    Transform<LimitQuery::MaxComputeUniformBlocks> MaxComputeUniformBlocks;
    Transform<LimitQuery::MaxComputeUniformComponents>
      MaxComputeUniformComponents;
    Transform<LimitQuery::MaxCombinedComputeUniformComponents>
      MaxCombinedComputeUniformComponents;
    Transform<LimitQuery::MaxComputeTextureImageUnits>
      MaxComputeTextureImageUnits;
    Transform<LimitQuery::MaxViewportDims> MaxViewportDims;
    Transform<LimitQuery::MaxViewports> MaxViewports;
    Transform<LimitQuery::MaxComputeWorkGroupCount> MaxComputeWorkGroupCount;
    Transform<LimitQuery::MaxComputeWorkGroupSize> MaxComputeWorkGroupSize;
    Transform<LimitQuery::MaxComputeWorkGroupInvocations>
      MaxComputeWorkGroupInvocations;
    Transform<LimitQuery::MaxComputeSharedMemorySize>
      MaxComputeSharedMemorySize;
    Transform<LimitQuery::MinFragmentInterpolationOffset>
      MinFragmentInterpolationOffset;
    Transform<LimitQuery::MinMapBufferAlignment> MinMapBufferAlignment;
    Transform<LimitQuery::MinProgramTexelOffset> MinProgramTexelOffset;
    Transform<LimitQuery::MinProgramTextureGatherOffset>
      MinProgramTextureGatherOffset;
};

} // namespace enums
#endif
//]
