#ifndef SDL_AUDIO_H
#define SDL_AUDIO_H

#include "util/common.h"

#include <SDL.h>

struct GBASDLAudio {
	// Input
	size_t samples;

	// State
	SDL_AudioSpec desiredSpec;
	SDL_AudioSpec obtainedSpec;
	float drift;
	float ratio;

	struct GBAAudio* audio;
	struct GBAThread* thread;
};

bool GBASDLInitAudio(struct GBASDLAudio* context);
void GBASDLDeinitAudio(struct GBASDLAudio* context);

#endif
