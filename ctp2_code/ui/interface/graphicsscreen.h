sint32 graphicsscreen_displayMyWindow();
sint32 graphicsscreen_removeMyWindow(uint32 action);
AUI_ERRCODE graphicsscreen_Initialize( void );
void graphicsscreen_Cleanup();
void graphicsscreen_getValues(sint32 &bright, sint32 &gamma, sint32 &color,sint32 &contrast);

void graphicsscreen_screensizeSelect(aui_Control *control, uint32 action, uint32 data, void *cookie );

void graphicsscreen_exitPress(aui_Control *control, uint32 action, uint32 data, void *cookie );
void graphicsscreen_checkPress(aui_Control *control, uint32 action, uint32 data, void *cookie );

void graphicsscreen_selectResolution(aui_Control *control, uint32 action, uint32 data, void *cookie);

void graphicsscreen_brightSlide(aui_Control *control, uint32 action, uint32 data, void *cookie );
void graphicsscreen_gammaSlide(aui_Control *control, uint32 action, uint32 data, void *cookie );
void graphicsscreen_colorSlide(aui_Control *control, uint32 action, uint32 data, void *cookie );
void graphicsscreen_contrastSlide(aui_Control *control, uint32 action, uint32 data, void *cookie );

enum
{
	GS_WALK,

	GS_TRADE,
	GS_WONDER,

	GS_POLITICALBORDERS,
	GS_TRADEROUTES,
	GS_WATER,

	GS_CITYINFLUENCE,
	GS_GRID,
	GS_ARMYNAMES,
	GS_CIVFLAGS,
	GS_SMOOTH,
	GS_GOODANIMS,
	GS_WINDOWED_MODE,
	GS_CITYPROD,

	GS_TOTAL
};

static uint32 check[] =
{
	GS_WALK,

	GS_TRADE,
	GS_WONDER,

	GS_POLITICALBORDERS,
	GS_TRADEROUTES,
	GS_WATER,

	GS_CITYINFLUENCE,
	GS_GRID,

	GS_ARMYNAMES,
	GS_CIVFLAGS,
	GS_SMOOTH,
	GS_GOODANIMS,
	GS_WINDOWED_MODE,
	GS_CITYPROD,

	GS_TOTAL
};