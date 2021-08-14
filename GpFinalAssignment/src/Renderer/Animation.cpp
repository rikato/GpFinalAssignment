#include "Animation.h"

#include <glm/gtx/matrix_interpolation.hpp>
#include <GLFW/glfw3.h>
#include <iostream>

Animation::Animation()
{
}

void Animation::Reset()
{
	m_ActiveKeyFrameIndex = 0;
}

void Animation::AddKeyFrame(KeyFrame keyframe)
{
	m_keyFrames.push_back(keyframe);
}

void Animation::NextKeyFrame() 
{
	// Reset the key frame delta for the next frame.
	m_KeyFrameDelta = 0.0f;

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

glm::mat4 Animation::Animate(double deltaTime)
{
	// Get the current key frame.	
	KeyFrame keyFrame = m_keyFrames.at(m_ActiveKeyFrameIndex);

	glm::mat4 transformState;

	// Interpolate between the current key frame transform and the previous or local transform based on key frame delta.
	transformState = glm::interpolate(m_ActiveKeyFrameIndex == 0 ? m_LocalTransform : m_keyFrames[m_ActiveKeyFrameIndex - 1].m_Transform, keyFrame.m_Transform, m_KeyFrameDelta);

	// Update the delta based on delta time, then normalize this result between 0 and 1.
	// This way the key frame delta is based on the delta time.
	m_KeyFrameDelta += deltaTime / keyFrame.length;

	// When the animation exceeds the key frame time we move to the next frame.
	if (m_KeyFrameDelta >= 1) 
	{
		NextKeyFrame();
	}

	return transformState;
}

void Animation::SetLocalTransform(glm::mat4 transform)
{
	m_LocalTransform = transform;
}
