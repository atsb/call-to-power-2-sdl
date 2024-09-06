//
// The implementation of aui_SDLMovie is a stripped version of ffplay.c.
// ffplay.c is part of ffmpeg (https://github.com/FFmpeg/FFmpeg).
// The version used is 3.4 with some version 4.2 modifications.
//

#include "c3.h"
#include "aui_sdlmovie.h"

#if defined(__AUI_USE_SDL__)

struct VideoState {
};

aui_SDLMovie::aui_SDLMovie(AUI_ERRCODE *retval, const MBCHAR * filename) :
	aui_Movie(),
	m_videoState(NULL),
	m_renderer(NULL),
	m_background(NULL),
	m_windowWidth(0),
	m_windowHeight(0),
	m_logicalWidth(0),
	m_logicalHeight(0)
{
	strncpy(m_filename, filename, sizeof(m_filename));
	m_filename[MAX_PATH] = '\0';
	*retval = AUI_ERRCODE_OK;
}

aui_SDLMovie::~aui_SDLMovie() {
	Assert(!m_videoState);
	m_renderer = NULL;
	m_background = NULL;
}

void aui_SDLMovie::SetContext(SDL_Renderer *renderer, SDL_Texture *background, const int windowWidth,
		const int windowHeight) {
	Assert(renderer);
	Assert(background);
	m_renderer = renderer;
	m_background = background;
	m_windowWidth = windowWidth;
	m_windowHeight = windowHeight;
}

AUI_ERRCODE aui_SDLMovie::Load() {
	return AUI_ERRCODE_OK;
}

AUI_ERRCODE aui_SDLMovie::Unload() {
	return Close();
}

AUI_ERRCODE aui_SDLMovie::Open(uint32 flags, aui_Surface *surface, RECT *rect) {

	return AUI_ERRCODE_OK;
}

AUI_ERRCODE aui_SDLMovie::Close() {

	return AUI_ERRCODE_OK;
}

AUI_ERRCODE aui_SDLMovie::Play() {
	return AUI_ERRCODE_OK;
}

AUI_ERRCODE aui_SDLMovie::Stop() {
	return AUI_ERRCODE_OK;
}

AUI_ERRCODE aui_SDLMovie::Pause() {

	return AUI_ERRCODE_OK;
}

AUI_ERRCODE aui_SDLMovie::Resume() {

}

AUI_ERRCODE aui_SDLMovie::Process() {

}

BOOL aui_SDLMovie::IsOpen() const {
	return m_videoState != NULL || m_isFinished;
}

BOOL aui_SDLMovie::IsPlaying() const {
	return FALSE;
}

BOOL aui_SDLMovie::IsPaused() const {
	return FALSE;
}

bool aui_SDLMovie::HandleMovieEvent(SDL_Event &event) {
	bool movieFinished = true;

	return movieFinished;
}


bool aui_SDLMovie::InsideMovieArea(int x, int y) {
	return true;
}

void aui_SDLMovie::GrabLastFrame() {
}
#endif // defined(__AUI_USE_SDL__)
