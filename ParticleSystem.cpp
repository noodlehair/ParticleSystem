#include "ParticleSystem.h"

ParticleSystem :: ParticleSystem(){
	flameEmitter = new FlameEmitter("falme.ppm");
	flashEmitter = new FlashEmitter("flash.ppm");
	shockwaveEmitter = new ShockwaveEmitter("shock.ppm");
	debrisEmitter = new DebrisEmitter("debris1.ppm",
		                                "debris2.ppm");

}

ParticleSystem :: ~ParticleSystem(){

	delete flameEmitter;
	delete flashEmitter;
	delete shockwaveEmitter;
	delete debrisEmitter;

}

void ParticleSystem :: display(){
	flashEmitter->flashEmitterDisplay();
	shockwaveEmitter->shockwaveEmitterDisplay();	
	flameEmitter->flameEmitterDisplay();
    debrisEmitter->debrisEmitterDisplay();
									

}