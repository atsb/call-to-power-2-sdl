//----------------------------------------------------------------------------
//
// Project      : Call To Power 2
// File type    : C++ source
// Description  : Activision User Interface - image handling
//
//----------------------------------------------------------------------------
//
// Disclaimer
//
// THIS FILE IS NOT GENERATED OR SUPPORTED BY ACTIVISION.
//
// This material has been developed at apolyton.net by the Apolyton CtP2
// Source Code Project. Contact the authors at ctp2source@apolyton.net.
//
//----------------------------------------------------------------------------
//
// Compiler flags
//
// - None
//
//----------------------------------------------------------------------------
//
// Modifications from the original Activision code:
//
// - Crash prevented.
// - Initialized local variables. (Sep 9th 2005 Martin Gühmann)
//
//----------------------------------------------------------------------------

#include "c3.h"

#include "aui_blitter.h"
#include "aui_Factory.h"
#include "aui_image.h"
#include "aui_memmap.h"
#include "aui_pixel.h"
#include "aui_ui.h"

#include "../aui_sdl/aui_sdlsurface.h"

aui_Image::aui_Image(
	AUI_ERRCODE *retval,
	const MBCHAR * filename )
	:
	aui_Base()
{

	if (filename==NULL)
	{
		*retval = AUI_ERRCODE_OK;
		return;
	}

	*retval = InitCommon( filename );
	Assert( AUI_SUCCESS(*retval) );
	if ( !AUI_SUCCESS(*retval) ) return;
}

AUI_ERRCODE aui_Image::InitCommon( const MBCHAR *filename )
{
	m_surface = NULL,
	m_format = NULL;

	AUI_ERRCODE errcode = SetFilename( filename );
	Assert( AUI_SUCCESS(errcode) );
	if ( !AUI_SUCCESS(errcode) ) return errcode;

	return AUI_ERRCODE_OK;
}

aui_Image::~aui_Image()
{
	Unload();
}

AUI_ERRCODE aui_Image::SetFilename( const MBCHAR *filename )
{
	Unload();	// deletes and NULLs m_format and m_surface

	memset( m_filename, '\0', sizeof( m_filename ) );

	if ( !filename ) return AUI_ERRCODE_INVALIDPARAM;

#ifndef _WIN32
	strncpy(m_filename, CI_FixName(filename), MAX_PATH);
#else
	strncpy(m_filename, filename, MAX_PATH);
#endif

	if (g_ui && g_ui->TheMemMap())
	{
		m_format = static_cast<aui_ImageFormat *>
						(g_ui->TheMemMap()->GetFileFormat(m_filename));
	}

	Assert(m_format);
	return m_format ? AUI_ERRCODE_OK : AUI_ERRCODE_MEMALLOCFAILED;
}

AUI_ERRCODE aui_Image::Load( void )
{
	Assert(m_format);
	if ( !m_format ) return AUI_ERRCODE_INVALIDPARAM;

	if ( m_surface ) return AUI_ERRCODE_OK;

	return m_format->Load(m_filename, this);
}

AUI_ERRCODE aui_Image::Unload( void )
{
	if (g_ui && g_ui->TheMemMap())
	{
		g_ui->TheMemMap()->ReleaseFileFormat(m_format);
		m_format = NULL;
	}

	delete  m_surface;
	m_surface = NULL;

	return AUI_ERRCODE_OK;
}

AUI_ERRCODE aui_Image::LoadEmpty( sint32 width, sint32 height, sint32 bpp )
{
	AUI_ERRCODE errcode = AUI_ERRCODE_OK;

	m_surface = aui_Factory::new_Surface(errcode, width, height);

	Assert( AUI_NEWOK(m_surface, errcode) );
	return errcode;
}

AUI_ERRCODE aui_Image::LoadFileMapped( sint32 width, sint32 height,
                                       sint32 bpp, sint32 pitch,
                                       uint8 *buffer )
{
	AUI_ERRCODE retcode = AUI_ERRCODE_OK;

	m_surface = new aui_Surface(
	    &retcode,
	    width,
	    height,
	    bpp,
	    pitch,
	    buffer );

	Assert( AUI_NEWOK(m_surface,retcode) );

	return retcode;
}

AUI_ERRCODE aui_BmpImageFormat::Load(MBCHAR const * filename, aui_Image *image )
{
	AUI_ERRCODE retcode = AUI_ERRCODE_OK;

	fprintf(stderr, "%s L%d: image %s!\n", __FILE__, __LINE__, filename); //is this ever called?
	Assert(0);
	SDL_Surface *bmp = SDL_LoadBMP(filename);
	SDL_Surface *surf = NULL;
	SDL_PixelFormat fmt = { 0 };

        fprintf(stderr, "%s L%d: image %s!\n", __FILE__, __LINE__, filename);
        if (g_ui->Primary()->BitsPerPixel() != 16)
            fprintf(stderr, "%s L%d: bpp %d", __FILE__, __LINE__,  g_ui->Primary()->BitsPerPixel());
        if (bmp->format->Gmask >> bmp->format->Gshift == 0x3F)
            fprintf(stderr, "%s L%d: 565 image!\n", __FILE__, __LINE__);
        if (bmp->format->Gmask >> bmp->format->Gshift == 0x1F)
            fprintf(stderr, "%s L%d: 555 image!\n", __FILE__, __LINE__);
	if (NULL == surf) {
        SDL_PixelFormat *format = SDL_AllocFormat(aui_SDLSurface::TransformSurfacePixelFormatToSDL(g_ui->PixelFormat()));
        surf = SDL_ConvertSurface(bmp, format, 0);
        SDL_FreeFormat(format);
    }
	SDL_FreeSurface(bmp);
	if (NULL == surf)
		return AUI_ERRCODE_LOADFAILED;
	//surface = image->TheSurface();
	//image->AttachSurface(surf);
        //The new surface should be assinged to the image-surfec but how???
        //conversion needed from SDL_Surface to aui_Surface
        //also using SDL_BlitSurface might be good in case surf 565 and img 555
        /* //this part doesn't create a visible effect:
        AUI_ERRCODE *retval;

        if (m_surface) {
            delete m_surface;
            }

        m_surface = new aui_Surface(retval, s->w, s->h, s->format->BitsPerPixel, s->pitch, (uint8 *) s->pixels);
        Assert( AUI_SUCCESS(*retval) );
        if ( !AUI_SUCCESS(*retval) ) return;
        */

        if (image->TheSurface()) {
	} else {
	}
	return retcode;
}

void aui_Image::SetChromakey(sint32 r, sint32 g, sint32 b)
{
	aui_Surface		*surf = TheSurface();

	Assert(surf != NULL);
	if (surf == NULL)
		return;

	Assert(r >= 0);
	Assert(r <= 255);
	Assert(g >= 0);
	Assert(g <= 255);
	Assert(b >= 0);
	Assert(b <= 255);

	surf->SetChromaKey((uint8) r, (uint8) g,(uint8) b);
}
