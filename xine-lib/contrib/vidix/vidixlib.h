/*
 * vidixlib.h
 * VIDIXLib - Library for VIDeo Interface for *niX
 *   This interface is introduced as universal one to MPEG decoder,
 *   BES == Back End Scaler and YUV2RGB hw accelerators.
 * In the future it may be expanded up to capturing and audio things.
 * Main goal of this this interface imlpementation is providing DGA
 * everywhere where it's possible (unlike X11 and other).
 * Copyright 2002 Nick Kurshev
 * Licence: GPL
 * This interface is based on v4l2, fbvid.h, mga_vid.h projects
 * and personally my ideas.
 * NOTE: This interface is introduces as APP interface.
 * Don't use it for driver.
 * It provides multistreaming. This mean that APP can handle
 * several streams simultaneously. (Example: Video capturing and video
 * playback or capturing, video playback, audio encoding and so on).
*/
#ifndef VIDIXLIB_H
#define VIDIXLIB_H

#ifdef __cplusplus
extern "C" {
#endif

#include "vidix.h"

typedef void * VDL_HANDLE;

			/* returns library version */
extern unsigned   vdlGetVersion( void );

			/* Opens corresponded video driver and returns handle
			   of associated stream.
			   path - specifies path where drivers are located.
			   name - specifies prefered driver name (can be NULL).
			   cap  - specifies driver capability (TYPE_* constants).
			   verbose - specifies verbose level
			   returns !0 if ok else NULL.
			   */
extern VDL_HANDLE vdlOpen(const char *path,const char *name,unsigned cap,int verbose);
			/* Closes stream and corresponded driver. */
extern void	  vdlClose(VDL_HANDLE stream);

			/* Queries driver capabilities. Return 0 if ok else errno */
extern int	  vdlGetCapability(VDL_HANDLE, vidix_capability_t *);

			/* Queries support for given fourcc. Returns 0 if ok else errno */
extern int	  vdlQueryFourcc(VDL_HANDLE,vidix_fourcc_t *);

			/* Returns 0 if ok else errno */
extern int	  vdlConfigPlayback(VDL_HANDLE, vidix_playback_t *);

			/* Returns 0 if ok else errno */
extern int 	  vdlPlaybackOn(VDL_HANDLE);

			/* Returns 0 if ok else errno */
extern int 	  vdlPlaybackOff(VDL_HANDLE);

			/* Returns 0 if ok else errno */
extern int 	  vdlPlaybackFrameSelect(VDL_HANDLE, unsigned frame_idx );

			/* Returns 0 if ok else errno */
extern int 	  vdlGetGrKeys(VDL_HANDLE, vidix_grkey_t * );

			/* Returns 0 if ok else errno */
extern int 	  vdlSetGrKeys(VDL_HANDLE, const vidix_grkey_t * );

			/* Returns 0 if ok else errno */
extern int 	  vdlPlaybackGetEq(VDL_HANDLE, vidix_video_eq_t * );

			/* Returns 0 if ok else errno */
extern int 	  vdlPlaybackSetEq(VDL_HANDLE, const vidix_video_eq_t * );

			/* Returns 0 if ok else errno */
extern int	  vdlPlaybackGetDeint(VDL_HANDLE, vidix_deinterlace_t * );

			/* Returns 0 if ok else errno */
extern int 	  vdlPlaybackSetDeint(VDL_HANDLE, const vidix_deinterlace_t * );

			/* Returns 0 if ok else errno */
extern int	  vdlQueryNumOemEffects(VDL_HANDLE, unsigned * number );

			/* Returns 0 if ok else errno */
extern int	  vdlGetOemEffect(VDL_HANDLE, vidix_oem_fx_t * );

			/* Returns 0 if ok else errno */
extern int	  vdlSetOemEffect(VDL_HANDLE, const vidix_oem_fx_t * );


			/* Returns 0 if ok else errno */
extern int	  vdlPlaybackCopyFrame(VDL_HANDLE, vidix_dma_t * );

			/* Returns 0 if DMA is available else errno (EBUSY) */
extern int	  vdlQueryDMAStatus( VDL_HANDLE );

/*
  ABI related extensions.
  Note: you should use this functions if you are using shared version
  of vidix.
*/
extern vidix_capability_t *	vdlAllocCapabilityS( void );
extern vidix_fourcc_t *		vdlAllocFourccS( void );
extern vidix_playback_t *	vdlAllocPlaybackS( void );
extern vidix_yuv_t *		vdlAllocYUVS( void );
extern vidix_rect_t *		vdlAllocRectS( void );
extern vidix_grkey_t *		vdlAllocGrKeyS( void );
extern vidix_video_eq_t *	vdlAllocVideoEqS( void );
extern vidix_deinterlace_t *	vdlAllocDeinterlaceS( void );
extern vidix_dma_t *		vdlAllocDmaS( void );
extern vidix_oem_fx_t *		vdlAllocOemFxS( void );

extern void	vdlFreeCapabilityS(vidix_capability_t * );
extern void 	vdlFreeFourccS( vidix_fourcc_t * );
extern void	vdlFreePlaybackS( vidix_playback_t * );
extern void	vdlFreeYUVS( vidix_yuv_t * );
extern void	vdlFreeRectS( vidix_rect_t * );
extern void	vdlFreeGrKeyS( vidix_grkey_t * );
extern void	vdlFreeVideoEqS( vidix_video_eq_t * );
extern void	vdlFreeDeinterlaceS( vidix_deinterlace_t * );
extern void	vdlFreeDmaS( vidix_dma_t * );
extern void	vdlFreeOemFxS( vidix_oem_fx_t * );

#ifdef __cplusplus
}
#endif

#endif
