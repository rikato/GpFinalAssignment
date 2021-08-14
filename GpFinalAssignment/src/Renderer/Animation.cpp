#include "Animation.h"

#include <glm/gtx/matrix_interpolation.hpp>
#include <GLFW/glfw3.h>

Animation::Animation(float animationSpeed, bool infinite)
	: m_Speed(animationSpeed), m_Infinite(infinite)
{
}

void Animation::Reset()
{
	m_ActiveKeyFrameIndex = 0;
	// We also want to reset the delta for the next key frame.
	m_KeyFrameDelta = 0;
}

void Animation::AddKeyFrame(KeyFrame keyframe)
{
	m_keyFrames.push_back(keyframe);
}

void Animation::Start()
{
	
}

void Animation::Stop()
{
}

void Animation::NextKeyFrame() 
{
	if (m_ActiveKeyFrameIndex == m_keyFrames.size() -1) 
	{
		// When this was the last keyframe we reset it.
		Reset();
	}
	else 
	{
		// If the last key frame is not yet reached we move to the next one.
		m_ActiveKeyFrameIndex++;
	}
}

glm::mat4 Animation::Animate()
{
	// Get the current key frame.	
	KeyFrame keyFrame = m_keyFrames[m_ActiveKeyFrameIndex];

	glm::mat4 transformState;

	// Interpolate between the current key frame start and end-transform based on key frame delta.
	transformState = glm::interpolate(keyFrame.m_StartTransform, keyFrame.m_EndTransform, m_KeyFrameDelta);

	double currentFrameTime = glfwGetTime();

	// Update the delta based on delta time, then normalize this result between 0 and 1.
	// This way the key frame delta is based on the delta time.
	m_KeyFrameDelta += (currentFrameTime - m_frameTime) / keyFrame.length;

	m_frameTime = currentFrameTime;

	// When the animation exceeds the key frame time we move to the next frame.
	if (m_KeyFrameDelta >= 1) 
	{
		NextKeyFrame();
	}

	return transformState;
}
