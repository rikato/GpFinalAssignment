#pragma once

#include <glm/glm.hpp>
#include <vector>

struct  KeyFrame
{
	// The ending transform of this keyframe.
	glm::mat4 m_Transform;
	// The time it takes to complete this animation in seconds.
	float length;
};

class Animation 
{
private: 
	glm::mat4 m_LocalTransform;

	std::vector<KeyFrame> m_keyFrames;
	int m_ActiveKeyFrameIndex = 0;
	float m_KeyFrameDelta = 0.0f;

	void Reset();
public:
	Animation();

	void AddKeyFrame(KeyFrame keyframe);
	void NextKeyFrame();
	glm::mat4 Animate(double deltaTime);
	void SetLocalTransform(glm::mat4 transform);
};