#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=
AS=

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/DrawableGeometricObject.o \
	${OBJECTDIR}/ObservationCenter.o \
	${OBJECTDIR}/Image.o \
	${OBJECTDIR}/Menu.o \
	${OBJECTDIR}/IntervalAction.o \
	${OBJECTDIR}/DrawableObject.o \
	${OBJECTDIR}/Translation.o \
	${OBJECTDIR}/ColorEffect.o \
	${OBJECTDIR}/IntervalActionEffect.o \
	${OBJECTDIR}/IntervalActionTransformation.o \
	${OBJECTDIR}/DrawableCircle.o \
	${OBJECTDIR}/OpacityEffect.o \
	${OBJECTDIR}/Sprite.o \
	${OBJECTDIR}/ParticleSequencer.o \
	${OBJECTDIR}/DrawableLine.o \
	${OBJECTDIR}/Animation.o \
	${OBJECTDIR}/Layer.o \
	${OBJECTDIR}/MenuItem.o \
	${OBJECTDIR}/SOIL/stb_image_aug.o \
	${OBJECTDIR}/Particle.o \
	${OBJECTDIR}/Director.o \
	${OBJECTDIR}/DrawableRectangle.o \
	${OBJECTDIR}/TextureNode.o \
	${OBJECTDIR}/Camera.o \
	${OBJECTDIR}/Texture2D.o \
	${OBJECTDIR}/Clock.o \
	${OBJECTDIR}/SOIL/image_DXT.o \
	${OBJECTDIR}/Scene.o \
	${OBJECTDIR}/SOIL/SOIL.o \
	${OBJECTDIR}/Rotation.o \
	${OBJECTDIR}/RessourceMgr.o \
	${OBJECTDIR}/SimpleIntervalAction.o \
	${OBJECTDIR}/Observation.o \
	${OBJECTDIR}/OGLMatrix.o \
	${OBJECTDIR}/Object.o \
	${OBJECTDIR}/DrawableNode.o \
	${OBJECTDIR}/Scale.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-lGL -lglut
CXXFLAGS=-lGL -lglut

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/lib2DEngine.so

dist/Debug/GNU-Linux-x86/lib2DEngine.so: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${LINK.cc} -lGL -shared -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lib2DEngine.so -fPIC ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/DrawableGeometricObject.o: nbproject/Makefile-${CND_CONF}.mk DrawableGeometricObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/DrawableGeometricObject.o DrawableGeometricObject.cpp

${OBJECTDIR}/ObservationCenter.o: nbproject/Makefile-${CND_CONF}.mk ObservationCenter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/ObservationCenter.o ObservationCenter.cpp

${OBJECTDIR}/Image.o: nbproject/Makefile-${CND_CONF}.mk Image.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Image.o Image.cpp

${OBJECTDIR}/Menu.o: nbproject/Makefile-${CND_CONF}.mk Menu.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Menu.o Menu.cpp

${OBJECTDIR}/IntervalAction.o: nbproject/Makefile-${CND_CONF}.mk IntervalAction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/IntervalAction.o IntervalAction.cpp

${OBJECTDIR}/DrawableObject.o: nbproject/Makefile-${CND_CONF}.mk DrawableObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/DrawableObject.o DrawableObject.cpp

${OBJECTDIR}/Translation.o: nbproject/Makefile-${CND_CONF}.mk Translation.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Translation.o Translation.cpp

${OBJECTDIR}/ColorEffect.o: nbproject/Makefile-${CND_CONF}.mk ColorEffect.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/ColorEffect.o ColorEffect.cpp

${OBJECTDIR}/IntervalActionEffect.o: nbproject/Makefile-${CND_CONF}.mk IntervalActionEffect.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/IntervalActionEffect.o IntervalActionEffect.cpp

${OBJECTDIR}/IntervalActionTransformation.o: nbproject/Makefile-${CND_CONF}.mk IntervalActionTransformation.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/IntervalActionTransformation.o IntervalActionTransformation.cpp

${OBJECTDIR}/DrawableCircle.o: nbproject/Makefile-${CND_CONF}.mk DrawableCircle.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/DrawableCircle.o DrawableCircle.cpp

${OBJECTDIR}/OpacityEffect.o: nbproject/Makefile-${CND_CONF}.mk OpacityEffect.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/OpacityEffect.o OpacityEffect.cpp

${OBJECTDIR}/Sprite.o: nbproject/Makefile-${CND_CONF}.mk Sprite.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sprite.o Sprite.cpp

${OBJECTDIR}/ParticleSequencer.o: nbproject/Makefile-${CND_CONF}.mk ParticleSequencer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/ParticleSequencer.o ParticleSequencer.cpp

${OBJECTDIR}/DrawableLine.o: nbproject/Makefile-${CND_CONF}.mk DrawableLine.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/DrawableLine.o DrawableLine.cpp

${OBJECTDIR}/Animation.o: nbproject/Makefile-${CND_CONF}.mk Animation.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Animation.o Animation.cpp

${OBJECTDIR}/Layer.o: nbproject/Makefile-${CND_CONF}.mk Layer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Layer.o Layer.cpp

${OBJECTDIR}/MenuItem.o: nbproject/Makefile-${CND_CONF}.mk MenuItem.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/MenuItem.o MenuItem.cpp

${OBJECTDIR}/SOIL/stb_image_aug.o: nbproject/Makefile-${CND_CONF}.mk SOIL/stb_image_aug.c 
	${MKDIR} -p ${OBJECTDIR}/SOIL
	${RM} $@.d
	$(COMPILE.c) -g -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/SOIL/stb_image_aug.o SOIL/stb_image_aug.c

${OBJECTDIR}/Particle.o: nbproject/Makefile-${CND_CONF}.mk Particle.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Particle.o Particle.cpp

${OBJECTDIR}/Director.o: nbproject/Makefile-${CND_CONF}.mk Director.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Director.o Director.cpp

${OBJECTDIR}/DrawableRectangle.o: nbproject/Makefile-${CND_CONF}.mk DrawableRectangle.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/DrawableRectangle.o DrawableRectangle.cpp

${OBJECTDIR}/TextureNode.o: nbproject/Makefile-${CND_CONF}.mk TextureNode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/TextureNode.o TextureNode.cpp

${OBJECTDIR}/Camera.o: nbproject/Makefile-${CND_CONF}.mk Camera.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Camera.o Camera.cpp

${OBJECTDIR}/Texture2D.o: nbproject/Makefile-${CND_CONF}.mk Texture2D.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Texture2D.o Texture2D.cpp

${OBJECTDIR}/Clock.o: nbproject/Makefile-${CND_CONF}.mk Clock.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Clock.o Clock.cpp

${OBJECTDIR}/SOIL/image_DXT.o: nbproject/Makefile-${CND_CONF}.mk SOIL/image_DXT.c 
	${MKDIR} -p ${OBJECTDIR}/SOIL
	${RM} $@.d
	$(COMPILE.c) -g -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/SOIL/image_DXT.o SOIL/image_DXT.c

${OBJECTDIR}/Scene.o: nbproject/Makefile-${CND_CONF}.mk Scene.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Scene.o Scene.cpp

${OBJECTDIR}/SOIL/SOIL.o: nbproject/Makefile-${CND_CONF}.mk SOIL/SOIL.c 
	${MKDIR} -p ${OBJECTDIR}/SOIL
	${RM} $@.d
	$(COMPILE.c) -g -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/SOIL/SOIL.o SOIL/SOIL.c

${OBJECTDIR}/Rotation.o: nbproject/Makefile-${CND_CONF}.mk Rotation.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Rotation.o Rotation.cpp

${OBJECTDIR}/RessourceMgr.o: nbproject/Makefile-${CND_CONF}.mk RessourceMgr.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/RessourceMgr.o RessourceMgr.cpp

${OBJECTDIR}/SimpleIntervalAction.o: nbproject/Makefile-${CND_CONF}.mk SimpleIntervalAction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/SimpleIntervalAction.o SimpleIntervalAction.cpp

${OBJECTDIR}/Observation.o: nbproject/Makefile-${CND_CONF}.mk Observation.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Observation.o Observation.cpp

${OBJECTDIR}/OGLMatrix.o: nbproject/Makefile-${CND_CONF}.mk OGLMatrix.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/OGLMatrix.o OGLMatrix.cpp

${OBJECTDIR}/Object.o: nbproject/Makefile-${CND_CONF}.mk Object.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Object.o Object.cpp

${OBJECTDIR}/DrawableNode.o: nbproject/Makefile-${CND_CONF}.mk DrawableNode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/DrawableNode.o DrawableNode.cpp

${OBJECTDIR}/Scale.o: nbproject/Makefile-${CND_CONF}.mk Scale.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DLINUX -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Scale.o Scale.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/lib2DEngine.so

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
