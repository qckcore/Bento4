/*****************************************************************
|
|    Bento4 - C API Main Header
|
|    Copyright 2002-2008 Gilles Boccon-Gibod & Julien Boeuf
|
|
|    This file is part of Bento4/AP4 (MP4 Atom Processing Library).
|
|    Unless you have obtained Bento4 under a difference license,
|    this version of Bento4 is Bento4|GPL.
|    Bento4|GPL is free software; you can redistribute it and/or modify
|    it under the terms of the GNU General Public License as published by
|    the Free Software Foundation; either version 2, or (at your option)
|    any later version.
|
|    Bento4|GPL is distributed in the hope that it will be useful,
|    but WITHOUT ANY WARRANTY; without even the implied warranty of
|    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
|    GNU General Public License for more details.
|
|    You should have received a copy of the GNU General Public License
|    along with Bento4|GPL; see the file COPYING.  If not, write to the
|    Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA
|    02111-1307, USA.
|
 ****************************************************************/

/*----------------------------------------------------------------------
|   includes
+---------------------------------------------------------------------*/
#include "Ap4Types.h"

/*----------------------------------------------------------------------
|   types
+---------------------------------------------------------------------*/
typedef struct AP4_ByteStream AP4_ByteStream;
typedef struct AP4_DataBuffer AP4_DataBuffer;
typedef struct AP4_File AP4_File;
typedef struct AP4_Movie AP4_Movie;
typedef struct AP4_Track AP4_Track;
typedef struct AP4_MetaData AP4_MetaData;
typedef struct AP4_Sample AP4_Sample;
typedef struct AP4_SampleDescription AP4_SampleDescription;
typedef struct AP4_AudioSampleDescription AP4_AudioSampleDescription;
typedef struct AP4_VideoSampleDescription AP4_VideoSampleDescription;
typedef struct AP4_AvcSampleDescription AP4_AvcSampleDescription;
typedef struct AP4_MpegSampleDescription AP4_MpegSampleDescription;
typedef struct AP4_MpegAudioSampleDescription AP4_MpegAudioSampleDescription;
typedef struct AP4_SyntheticSampleTable AP4_SyntheticSampleTable;

/*----------------------------------------------------------------------
|   constants
+---------------------------------------------------------------------*/
extern const int AP4_FILE_BYTE_STREAM_MODE_READ;
extern const int AP4_FILE_BYTE_STREAM_MODE_WRITE;
extern const int AP4_FILE_BYTE_STREAM_MODE_READ_WRITE;

extern const int AP4_TRACK_TYPE_UNKNOWN;
extern const int AP4_TRACK_TYPE_AUDIO;
extern const int AP4_TRACK_TYPE_VIDEO;
extern const int AP4_TRACK_TYPE_SYSTEM;
extern const int AP4_TRACK_TYPE_HINT;
extern const int AP4_TRACK_TYPE_TEXT;
extern const int AP4_TRACK_TYPE_JPEG;
extern const int AP4_TRACK_TYPE_RTP;

extern const AP4_UI32 AP4_HANDLER_TYPE_SOUN;
extern const AP4_UI32 AP4_HANDLER_TYPE_VIDE;
extern const AP4_UI32 AP4_HANDLER_TYPE_HINT;
extern const AP4_UI32 AP4_HANDLER_TYPE_MDIR;
extern const AP4_UI32 AP4_HANDLER_TYPE_TEXT;
extern const AP4_UI32 AP4_HANDLER_TYPE_TX3G;
extern const AP4_UI32 AP4_HANDLER_TYPE_JPEG;
extern const AP4_UI32 AP4_HANDLER_TYPE_ODSM;
extern const AP4_UI32 AP4_HANDLER_TYPE_SDSM;

extern const AP4_UI32 AP4_TRACK_DEFAULT_MOVIE_TIMESCALE;

extern const int AP4_SAMPLE_DESCRIPTION_TYPE_UNKNOWN;
extern const int AP4_SAMPLE_DESCRIPTION_TYPE_MPEG;
extern const int AP4_SAMPLE_DESCRIPTION_TYPE_PROTECTED;
extern const int AP4_SAMPLE_DESCRIPTION_TYPE_AVC;

extern const AP4_UI08 AP4_STREAM_TYPE_FORBIDDEN;
extern const AP4_UI08 AP4_STREAM_TYPE_OD;
extern const AP4_UI08 AP4_STREAM_TYPE_CR;	
extern const AP4_UI08 AP4_STREAM_TYPE_BIFS;
extern const AP4_UI08 AP4_STREAM_TYPE_VISUAL;
extern const AP4_UI08 AP4_STREAM_TYPE_AUDIO;
extern const AP4_UI08 AP4_STREAM_TYPE_MPEG7;
extern const AP4_UI08 AP4_STREAM_TYPE_IPMP;
extern const AP4_UI08 AP4_STREAM_TYPE_OCI;
extern const AP4_UI08 AP4_STREAM_TYPE_MPEGJ;
extern const AP4_UI08 AP4_STREAM_TYPE_TEXT;

extern const AP4_UI08 AP4_OTI_MPEG4_SYSTEM;
extern const AP4_UI08 AP4_OTI_MPEG4_SYSTEM_COR;
extern const AP4_UI08 AP4_OTI_MPEG4_TEXT;
extern const AP4_UI08 AP4_OTI_MPEG4_VISUAL;
extern const AP4_UI08 AP4_OTI_MPEG4_AUDIO;
extern const AP4_UI08 AP4_OTI_MPEG2_VISUAL_SIMPLE;
extern const AP4_UI08 AP4_OTI_MPEG2_VISUAL_MAIN;
extern const AP4_UI08 AP4_OTI_MPEG2_VISUAL_SNR;
extern const AP4_UI08 AP4_OTI_MPEG2_VISUAL_SPATIAL;
extern const AP4_UI08 AP4_OTI_MPEG2_VISUAL_HIGH;
extern const AP4_UI08 AP4_OTI_MPEG2_VISUAL_422;
extern const AP4_UI08 AP4_OTI_MPEG2_AAC_AUDIO_MAIN;
extern const AP4_UI08 AP4_OTI_MPEG2_AAC_AUDIO_LC;
extern const AP4_UI08 AP4_OTI_MPEG2_AAC_AUDIO_SSRP;
extern const AP4_UI08 AP4_OTI_MPEG2_PART3_AUDIO;
extern const AP4_UI08 AP4_OTI_MPEG1_VISUAL;
extern const AP4_UI08 AP4_OTI_MPEG1_AUDIO;
extern const AP4_UI08 AP4_OTI_JPEG;

extern const AP4_UI08 AP4_MPEG4_AUDIO_OBJECT_TYPE_AAC_MAIN;        /**< AAC Main Profile              */
extern const AP4_UI08 AP4_MPEG4_AUDIO_OBJECT_TYPE_AAC_LC;          /**< AAC Low Complexity            */
extern const AP4_UI08 AP4_MPEG4_AUDIO_OBJECT_TYPE_AAC_SSR;         /**< AAC Scalable Sample Rate      */
extern const AP4_UI08 AP4_MPEG4_AUDIO_OBJECT_TYPE_AAC_LTP;         /**< AAC Long Term Predictor       */
extern const AP4_UI08 AP4_MPEG4_AUDIO_OBJECT_TYPE_SBR;             /**< Spectral Band Replication          */
extern const AP4_UI08 AP4_MPEG4_AUDIO_OBJECT_TYPE_AAC_SCALABLE;    /**< AAC Scalable                       */
extern const AP4_UI08 AP4_MPEG4_AUDIO_OBJECT_TYPE_TWINVQ;          /**< Twin VQ                            */
extern const AP4_UI08 AP4_MPEG4_AUDIO_OBJECT_TYPE_ER_AAC_LC;       /**< Error Resilient AAC Low Complexity */
extern const AP4_UI08 AP4_MPEG4_AUDIO_OBJECT_TYPE_ER_AAC_LTP;      /**< Error Resilient AAC Long Term Prediction */
extern const AP4_UI08 AP4_MPEG4_AUDIO_OBJECT_TYPE_ER_AAC_SCALABLE; /**< Error Resilient AAC Scalable */
extern const AP4_UI08 AP4_MPEG4_AUDIO_OBJECT_TYPE_ER_TWINVQ;       /**< Error Resilient Twin VQ */
extern const AP4_UI08 AP4_MPEG4_AUDIO_OBJECT_TYPE_ER_BSAC;         /**< Error Resilient Bit Sliced Arithmetic Coding */
extern const AP4_UI08 AP4_MPEG4_AUDIO_OBJECT_TYPE_ER_AAC_LD;       /**< Error Resilient AAC Low Delay */
extern const AP4_UI08 AP4_MPEG4_AUDIO_OBJECT_TYPE_LAYER_1;         /**< MPEG Layer 1 */
extern const AP4_UI08 AP4_MPEG4_AUDIO_OBJECT_TYPE_LAYER_2;         /**< MPEG Layer 2 */
extern const AP4_UI08 AP4_MPEG4_AUDIO_OBJECT_TYPE_LAYER_3;         /**< MPEG Layer 3 */

extern const AP4_Cardinal AP4_SYNTHETIC_SAMPLE_TABLE_DEFAULT_CHUNK_SIZE;

/*----------------------------------------------------------------------
|   result codes
+---------------------------------------------------------------------*/
extern const int AP4_SUCCESS;
extern const int AP4_FAILURE;
extern const int AP4_ERROR_OUT_OF_MEMORY;
extern const int AP4_ERROR_INVALID_PARAMETERS;
extern const int AP4_ERROR_NO_SUCH_FILE;
extern const int AP4_ERROR_PERMISSION_DENIED;
extern const int AP4_ERROR_CANNOT_OPEN_FILE;
extern const int AP4_ERROR_EOS;
extern const int AP4_ERROR_WRITE_FAILED;
extern const int AP4_ERROR_READ_FAILED;
extern const int AP4_ERROR_INVALID_FORMAT;
extern const int AP4_ERROR_NO_SUCH_ITEM;
extern const int AP4_ERROR_OUT_OF_RANGE;
extern const int AP4_ERROR_INTERNAL;
extern const int AP4_ERROR_INVALID_STATE;
extern const int AP4_ERROR_LIST_EMPTY;
extern const int AP4_ERROR_LIST_OPERATION_ABORTED;
extern const int AP4_ERROR_INVALID_RTP_CONSTRUCTOR_TYPE;
extern const int AP4_ERROR_NOT_SUPPORTED;
extern const int AP4_ERROR_INVALID_TRACK_TYPE;
extern const int AP4_ERROR_INVALID_RTP_PACKET_EXTRA_DATA;
extern const int AP4_ERROR_BUFFER_TOO_SMALL;
extern const int AP4_ERROR_NOT_ENOUGH_DATA;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*----------------------------------------------------------------------
|   AP4_ByteStream methods
+---------------------------------------------------------------------*/
void 
AP4_ByteStream_AddReference(AP4_ByteStream* self);

void 
AP4_ByteStream_Release(AP4_ByteStream* self);

AP4_Result 
AP4_ByteStream_ReadPartial(AP4_ByteStream*  self,
                           void*            buffer,
                           AP4_Size         bytes_to_read,
                           AP4_Size*        bytes_read);

AP4_Result 
AP4_ByteStream_Read(AP4_ByteStream* self, 
                    void*           buffer, 
                    AP4_Size        bytes_to_read);

AP4_Result 
AP4_ByteStream_ReadDouble(AP4_ByteStream* self, double* value);

AP4_Result 
AP4_ByteStream_ReadUI64(AP4_ByteStream* self, AP4_UI64* value);

AP4_Result 
AP4_ByteStream_ReadUI32(AP4_ByteStream* self, AP4_UI32* value);

AP4_Result 
AP4_ByteStream_ReadUI24(AP4_ByteStream* self, AP4_UI32* value);

AP4_Result 
AP4_ByteStream_ReadUI16(AP4_ByteStream* self, AP4_UI16* value);

AP4_Result 
AP4_ByteStream_ReadUI08(AP4_ByteStream* self, AP4_UI08* value);

AP4_Result 
AP4_ByteStream_ReadString(AP4_ByteStream* self, 
                          char*           buffer, 
                          AP4_Size        size);

AP4_Result 
AP4_ByteStream_WritePartial(AP4_ByteStream* self,
                            const void*     buffer,
                            AP4_Size        bytes_to_write,
                            AP4_Size*       bytes_written);

AP4_Result 
AP4_ByteStream_Write(AP4_ByteStream* self, 
                     const void*     buffer, 
                     AP4_Size        bytes_to_write);
AP4_Result 
AP4_ByteStream_WriteDouble(AP4_ByteStream* self, double value);

AP4_Result 
AP4_ByteStream_WriteUI64(AP4_ByteStream* self, AP4_UI64 value);

AP4_Result 
AP4_ByteStream_WriteUI32(AP4_ByteStream* self, AP4_UI32 value);

AP4_Result 
AP4_ByteStream_WriteUI24(AP4_ByteStream* self, AP4_UI32 value);

AP4_Result 
AP4_ByteStream_WriteUI16(AP4_ByteStream* self, AP4_UI16 value);

AP4_Result 
AP4_ByteStream_WriteUI08(AP4_ByteStream* self, AP4_UI08 value);

AP4_Result 
AP4_ByteStream_WriteString(AP4_ByteStream* self, const char* buffer);

AP4_Result 
AP4_ByteStream_Seek(AP4_ByteStream* self, AP4_Position position);

AP4_Result 
AP4_ByteStream_Tell(AP4_ByteStream* self, AP4_Position* position);

AP4_Result 
AP4_ByteStream_GetSize(AP4_ByteStream* self, AP4_LargeSize* size);

AP4_Result 
AP4_ByteStream_CopyTo(AP4_ByteStream* self, 
                      AP4_ByteStream* receiver, 
                      AP4_LargeSize   size); 

AP4_Result Ap4_ByteStream_Flush(AP4_ByteStream* self);

/*----------------------------------------------------------------------
|   AP4_ByteStream construtors
+---------------------------------------------------------------------*/
AP4_ByteStream* 
AP4_SubStream_Create(AP4_ByteStream* container, 
                     AP4_Position     position, 
                     AP4_LargeSize    size);
AP4_ByteStream* 
AP4_MemoryByteStream_Create(AP4_Size size);

AP4_ByteStream* 
AP4_MemoryByteStream_FromBuffer(const AP4_UI08* buffer, AP4_Size size);

AP4_ByteStream*
AP4_MemoryByteStream_AdaptDataBuffer(AP4_DataBuffer* buffer); /* data is read/written from the supplied data buffer */

AP4_ByteStream*
AP4_FileByteStream_Create(const char* name, int mode, AP4_Result* result);

/*----------------------------------------------------------------------
|   AP4_DataBuffer methods
+---------------------------------------------------------------------*/
AP4_Result 
AP4_DataBuffer_SetBuffer(AP4_DataBuffer* self, AP4_Byte* buffer, AP4_Size size);

AP4_Result 
AP4_DataBuffer_SetBufferSize(AP4_DataBuffer* self, AP4_Size size);

AP4_Size 
AP4_DataBuffer_GetBufferSize(const AP4_DataBuffer* self);

const AP4_Byte*
AP4_DataBuffer_GetData(const AP4_DataBuffer* self);

AP4_Byte*
AP4_DataBuffer_UseData(AP4_DataBuffer* self);

AP4_Size
AP4_DataBuffer_GetDataSize(const AP4_DataBuffer* self);

AP4_Result
AP4_DataBuffer_SetDataSize(AP4_DataBuffer* self, AP4_Size size);

AP4_Result
AP4_DataBuffer_SetData(AP4_DataBuffer* self, 
                      const AP4_Byte*  data, 
                      AP4_Size         data_size);
                      
AP4_Result
AP4_DataBuffer_Reserve(AP4_DataBuffer* self, AP4_Size size);

void 
AP4_DataBuffer_Destroy(AP4_DataBuffer* self);

/*----------------------------------------------------------------------
|   AP4_DataBuffer constructors
+---------------------------------------------------------------------*/
AP4_DataBuffer*
AP4_DataBuffer_Create(AP4_Size size);

AP4_DataBuffer*
AP4_DataBuffer_FromData(const void* data, AP4_Size data_size);

AP4_DataBuffer*
AP4_DataBuffer_Clone(const AP4_DataBuffer* other);

/*----------------------------------------------------------------------
|   AP4_File methods
+---------------------------------------------------------------------*/
AP4_Movie*
AP4_File_GetMovie(AP4_File* self);

/* TODO AP4_File_GetFileType */

AP4_Result 
AP4_File_SetFileType(AP4_File*    self,
                     AP4_UI32     major_brand,
                     AP4_UI32     minor_version,
                     AP4_UI32*    compatible_brands,
                     AP4_Cardinal compatible_brand_count);
                     
int
AP4_File_IsMoovBeforeMdat(const AP4_File* self);

/* TODO AP4_File_Inspect */

const AP4_MetaData*
AP4_File_GetMetaData(AP4_File* self);

void
AP4_File_Destroy(AP4_File* self);

/*----------------------------------------------------------------------
|   AP4_File constructors
+---------------------------------------------------------------------*/
AP4_File*
AP4_File_Create(AP4_Movie* movie);

AP4_File*
AP4_File_FromStream(AP4_ByteStream* stream, int moov_only);

/*----------------------------------------------------------------------
|   AP4_Movie methods
+---------------------------------------------------------------------*/
AP4_Cardinal
AP4_Movie_GetTrackCount(AP4_Movie* self);

AP4_Track*
AP4_Movie_GetTrackByIndex(AP4_Movie* self, AP4_Ordinal index);

AP4_Track*
AP4_Movie_GetTrackById(AP4_Movie* self, AP4_UI32 track_id);

AP4_Track*
AP4_Movie_GetTrackByType(AP4_Movie* self, int type, AP4_Ordinal index);

AP4_UI32
AP4_Movie_GetTimeScale(AP4_Movie* self);

AP4_UI32
AP4_Movie_GetDuration(AP4_Movie* self);

AP4_Duration
AP4_Movie_GetDurationMs(AP4_Movie* self);

AP4_Result
AP4_Movie_AddTrack(AP4_Movie* self, AP4_Track* track);

void
AP4_Movie_Destroy(AP4_Movie* self);

/*----------------------------------------------------------------------
|   AP4_Movie constructors
+---------------------------------------------------------------------*/
AP4_Movie*
AP4_Movie_Create(AP4_UI32 time_scale);                          

/*----------------------------------------------------------------------
|   AP4_Track methods
+---------------------------------------------------------------------*/
int
AP4_Track_GetType(AP4_Track* self);

AP4_UI32
AP4_Track_GetHandlerType(AP4_Track* self);

AP4_UI32
AP4_Track_GetDuration(AP4_Track* self); /* timescale of the movie */

AP4_Duration
AP4_Track_GetDurationMs(AP4_Track* self);

AP4_Cardinal
AP4_Track_GetSampleCount(AP4_Track* self);

AP4_Result
AP4_Track_GetSample(AP4_Track* self, AP4_Ordinal index, AP4_Sample* sample);

AP4_Result
AP4_Track_ReadSample(AP4_Track*      self, 
                     AP4_Ordinal     index, 
                     AP4_Sample*     sample,
                     AP4_DataBuffer* data);

AP4_Result
AP4_Track_GetSampleIndexForTimeStampMs(AP4_Track*    self,
                                       AP4_TimeStamp ts,
                                       AP4_Ordinal*  index);
                                       
AP4_SampleDescription*
AP4_Track_GetSampleDescription(AP4_Track* self, AP4_Ordinal index);

AP4_UI32
AP4_Track_GetId(AP4_Track* self);

AP4_Result
AP4_Track_SetId(AP4_Track* self, AP4_UI32 track_id);

AP4_Result
AP4_Track_SetMovieTimeScale(AP4_Track* self, AP4_UI32 time_scale);

AP4_UI32
AP4_Track_GetMediaTimeScale(AP4_Track* self);

AP4_UI32
AP4_Track_GetMediaDuration(AP4_Track* self); /* in the timescale of the media */

const char* 
AP4_Track_GetName(AP4_Track* self);

const char*
AP4_Track_GetLanguage(AP4_Track* self);

void
AP4_Track_Destroy(AP4_Track* self);

/*----------------------------------------------------------------------
|   AP4_Track constructors
+---------------------------------------------------------------------*/
AP4_Track* 
AP4_Track_Create(int                       type,
                 AP4_SyntheticSampleTable* sample_table,
                 AP4_UI32                  track_id,
                 AP4_UI32                  movie_time_scale, /* 0 = use default */
                 AP4_UI32                  track_duration,   /* in the movie time scale */
                 AP4_UI32                  media_time_scale,
                 AP4_UI32                  media_duration,   /* in the media time scale */
                 const char*               language,
                 AP4_UI32                  width,
                 AP4_UI32                  height);

/*----------------------------------------------------------------------
|   AP4_SampleDescription methods
+---------------------------------------------------------------------*/
int
AP4_SampleDescription_GetType(AP4_SampleDescription* self);

AP4_UI32
AP4_SampleDescription_GetFormat(AP4_SampleDescription* self);

AP4_AudioSampleDescription*
AP4_SampleDescription_AsAudio(AP4_SampleDescription* self);

AP4_VideoSampleDescription*
AP4_SampleDescription_AsVideo(AP4_SampleDescription* self);

AP4_AvcSampleDescription*
AP4_SampleDescription_AsAvc(AP4_SampleDescription* self);

AP4_MpegSampleDescription*
AP4_SampleDescription_AsMpeg(AP4_SampleDescription* self);

AP4_MpegAudioSampleDescription*
AP4_SampleDescription_AsMpegAudio(AP4_SampleDescription* self);

AP4_UI32
AP4_AudioSampleDescription_GetSampleRate(AP4_AudioSampleDescription* self);

AP4_UI16
AP4_AudioSampleDescription_GetSampleSize(AP4_AudioSampleDescription* self);

AP4_UI16
AP4_AudioSampleDescription_GetChannelCount(AP4_AudioSampleDescription* self);

AP4_UI32
AP4_VideoSampleDescription_GetWidth(AP4_VideoSampleDescription* self);

AP4_UI16
AP4_VideoSampleDescription_GetHeight(AP4_VideoSampleDescription* self);

AP4_UI16
AP4_VideoSampleDescription_GetDepth(AP4_VideoSampleDescription* self);

const char*
AP4_VideoSampleDescription_GetCompressorName(AP4_VideoSampleDescription* self);

AP4_UI08
AP4_AvcSampleDescription_GetConfigurationVersion(AP4_AvcSampleDescription* self);

AP4_UI08
AP4_AvcSampleDescription_GetProfile(AP4_AvcSampleDescription* self);

AP4_UI08
AP4_AvcSampleDescription_GetLevel(AP4_AvcSampleDescription* self);

AP4_UI08
AP4_AvcSampleDescription_GetProfileCompatibility(AP4_AvcSampleDescription* self);

AP4_Cardinal
AP4_AvcSampleDescription_GetSequenceParameterCount(AP4_AvcSampleDescription* self);

const AP4_DataBuffer*
AP4_AvcSampleDescription_GetSequenceParameter(AP4_AvcSampleDescription* self,
                                              AP4_Ordinal               index);
                                              
AP4_Cardinal
AP4_AvcSampleDescription_GetPictureParameterCount(AP4_AvcSampleDescription* self);

const AP4_DataBuffer*
AP4_AvcSampleDescription_GetPictureParameter(AP4_AvcSampleDescription* self,
                                            AP4_Ordinal               index);
                                              
const AP4_DataBuffer*
AP4_AvcSampleDescription_GetRawBytes(AP4_AvcSampleDescription* self);

const char* 
AP4_AvcSampleDescription_GetProfileName(AP4_UI08 profile); /* class method */

AP4_UI08
AP4_MpegSampleDescription_GetStreamType(AP4_MpegSampleDescription* self);

AP4_UI08
AP4_MpegSampleDescription_GetObjectTypeId(AP4_MpegSampleDescription* self);

AP4_UI32
AP4_MpegSampleDescription_GetBufferSize(AP4_MpegSampleDescription* self);

AP4_UI32
AP4_MpegSampleDescription_GetMaxBitrate(AP4_MpegSampleDescription* self);

AP4_UI32
AP4_MpegSampleDescription_GetAvgBitrate(AP4_MpegSampleDescription* self);

const AP4_DataBuffer*
AP4_MpegSampleDescription_GetDecoderInfo(AP4_MpegSampleDescription* self);

AP4_UI08
AP4_MpegAudioSampleDescription_GetMpeg4AudioObjectType(AP4_MpegAudioSampleDescription* self);

const char*
AP4_MpegAudioSampleDescription_GetMpegAudioObjectTypeString(AP4_UI08 type); /* class method */

void AP4_SampleDescription_Destroy(AP4_SampleDescription* self);

/*----------------------------------------------------------------------
|   AP4_SampleDescription constructors
+---------------------------------------------------------------------*/
AP4_SampleDescription*
AP4_MpegVideoSampleDescription_Create(AP4_UI08        oti,
                                      AP4_UI16        width,
                                      AP4_UI16        height,
                                      AP4_UI16        depth,
                                      const char*     compressor_name,
                                      const AP4_Byte* decoder_info,
                                      AP4_Size        decoder_info_size,
                                      AP4_UI32        buffer_size,
                                      AP4_UI32        max_bitrate,
                                      AP4_UI32        avg_bitrate);

AP4_SampleDescription*
AP4_MpegAudioSampleDescription_Create(AP4_UI08        oti,
                                      AP4_UI32        sample_rate,
                                      AP4_UI32        sample_size,
                                      AP4_UI32        channel_count,
                                      const AP4_Byte* decoder_info,
                                      AP4_Size        decoder_info_size,
                                      AP4_UI32        buffer_size,
                                      AP4_UI32        max_bitrate,
                                      AP4_UI32        avg_bitrate);
                                      
AP4_SampleDescription*
AP4_MpegSystemSampleDescription_Create(AP4_UI08        stream_type,
                                       AP4_UI08        oti,
                                       const AP4_Byte* decoder_info,
                                       AP4_Size        decoder_info_size,
                                       AP4_UI32        buffer_size,
                                       AP4_UI32        max_bitrate,
                                       AP4_UI32        avg_bitrate);
                                       
AP4_SampleDescription*
AP4_AvcSampleDescription_Create(AP4_UI16         width,
                                AP4_UI16         height,
                                AP4_UI16         depth,
                                const char*      compressor_name,
                                AP4_UI08         config_version,
                                AP4_UI08         profile,
                                AP4_UI08         level,
                                AP4_UI08         profile_compatibility,
                                AP4_UI08         nalu_length_size,
                                AP4_DataBuffer** sequence_parameters,
                                AP4_Size         sequence_parameter_count,
                                AP4_DataBuffer** picture_parameters,
                                AP4_Size         picture_parameter_count);

/*----------------------------------------------------------------------
|   AP4_Sample methods
+---------------------------------------------------------------------*/
AP4_Result
AP4_Sample_ReadData(AP4_Sample* self, AP4_DataBuffer* data);

AP4_Result
AP4_Sample_ReadPartialData(AP4_Sample*     self, 
                           AP4_DataBuffer* data,
                           AP4_Size        size,
                           AP4_Size        offset);

AP4_ByteStream*
AP4_Sample_GetDataStream(AP4_Sample* self);

void
AP4_Sample_SetDataStream(AP4_Sample* self, AP4_ByteStream* stream);

AP4_Position
AP4_Sample_GetOffset(AP4_Sample* self);

void
AP4_Sample_SetOffset(AP4_Sample* self, AP4_Position offset);

AP4_Size
AP4_Sample_GetSize(AP4_Sample* self);

void
AP4_Sample_SetSize(AP4_Sample* self, AP4_Size size);

AP4_Ordinal
AP4_Sample_GetDescriptionIndex(AP4_Sample* self);

void
AP4_Sample_SetDescriptionIndex(AP4_Sample* self, AP4_Ordinal index);

AP4_UI32
AP4_Sample_GetDts(AP4_Sample* self);

void
AP4_SampleSetDts(AP4_Sample* self, AP4_UI32 dts);

AP4_UI32
AP4_Sample_GetCts(AP4_Sample* self);

void
AP4_Sample_SetCts(AP4_Sample* self, AP4_UI32 cts);

int
AP4_Sample_IsSync(AP4_Sample* self);

void
AP4_Sample_SetSync(AP4_Sample* self, int is_sync);

void
AP4_Sample_Destroy(AP4_Sample* self);

/*----------------------------------------------------------------------
|   AP4_Sample constructors
+---------------------------------------------------------------------*/
AP4_Sample*
AP4_Sample_CreateEmpty(void);

AP4_Sample*
AP4_Sample_Create(AP4_ByteStream* data_stream,
                  AP4_Position    offset,
                  AP4_Size        size,
                  AP4_Ordinal     description_index,
                  AP4_TimeStamp   dts,
                  AP4_UI32        cts_offset,
                  int             is_sync);
                  
AP4_Sample*
AP4_Sample_Clone(const AP4_Sample* other);

/*----------------------------------------------------------------------
|   AP4_SyntheticSampleTable methods
+---------------------------------------------------------------------*/
AP4_Result
AP4_SyntheticSampleTable_AddSampleDescription(AP4_SyntheticSampleTable* self,
                                              AP4_SampleDescription*    desc);
                                              
AP4_Result
AP4_SyntheticSampleTable_AddSample(AP4_SyntheticSampleTable* self,
                                   AP4_ByteStream*           data_stream,
                                   AP4_Position              offset,
                                   AP4_Size                  size,
                                   AP4_Ordinal               desc_index,
                                   AP4_TimeStamp             cts, 
                                   AP4_TimeStamp             dts,
                                   int                       is_sync);
                                   
/*----------------------------------------------------------------------
|   AP4_SyntheticSampleTable constructors
+---------------------------------------------------------------------*/
AP4_SyntheticSampleTable*
AP4_SyntheticSampleTable_Create(AP4_Cardinal chunk_size); /* see AP4_SYNTHETIC_SAMPLE_TABLE_DEFAULT_CHUNK_SIZE constant */

#ifdef __cplusplus
}
#endif /*__cplusplus */