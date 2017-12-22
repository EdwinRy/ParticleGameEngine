particleEngine = Particle/*.{cpp,h}
mathematics = ParticleMaths/*.{cpp,h}
physics = ParticlePhysics/*.{cpp,h}
tests = testing/*.{cpp,h}
compiler = g++
out = bin/ParticleEngine

all:
	$(compiler) \
	$(particleEngine) \
	$(mathematics) \
	$(physics) \
	$(tests) \
	-lSDL \
	-o $(out)