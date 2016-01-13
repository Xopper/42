#include "Windows.hpp"
#include "Mesh.hpp"
#include "Color.hpp"
#include "Matrix.hpp"
#include "Math.hpp"
#include "Shader.hpp"
#include "Animation.hpp"
#include "AddAnimator.hpp"
#include "SetAnimator.hpp"
#include "LerpAnimator.hpp"
#include "CerpAnimator.hpp"
#include "Node.hpp"
#include <iostream>

int main(void)
{
	Windows win(800, 600, "OpenGL");
	win.setClearColor(Color::White);

	std::unique_ptr<Animation>	trunkAnim(new Animation());
	trunkAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Rotate>(Vector3(0.f, 0.f, 0.f), 0.f)));
	trunkAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Scale>(Vector3(0.25f, 0.5f, 0.1f), 0.f)));
	trunkAnim->pushAnimator(Animation::AnimatorPtr(new AddAnimator<Anim::RotateY>(45.f, 0.f, 4.f)));

	std::unique_ptr<Animation>	armRightAnim(new Animation());
	armRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Origin>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	armRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Translate>(Vector3(-0.62f, 0.5f, 0.0f), 0.f)));
	armRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Scale>(Vector3(0.25f, 0.5f, 0.5f), 0.f)));
	armRightAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Rotate>(-Vector3(135.f, 0.f, 0.f), 0.f)));
	armRightAnim->pushAnimator(Animation::AnimatorPtr(new AddAnimator<Anim::RotateX>(-135.f, 0.f, 0.6f)));
	armRightAnim->pushAnimator(Animation::AnimatorPtr(new AddAnimator<Anim::RotateX>(135.f, 0.6f, 0.6f)));

	std::unique_ptr<Animation>	armLeftAnim(new Animation());
	armLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Origin>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	armLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Translate>(Vector3(0.62f, 0.5f, 0.0f), 0.f)));
	armLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Scale>(Vector3(0.25f, 0.5f, 0.5f), 0.f)));
	armLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Rotate>(Vector3(135.f, 0.f, 0.f), 0.f)));
	armLeftAnim->pushAnimator(Animation::AnimatorPtr(new AddAnimator<Anim::RotateX>(135.f, 0.f, 0.6f)));
	armLeftAnim->pushAnimator(Animation::AnimatorPtr(new AddAnimator<Anim::RotateX>(-135.f, 0.6f, 0.6f)));

	std::unique_ptr<Animation>	subArmLeftAnim(new Animation());
	subArmLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Origin>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	subArmLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Translate>(Vector3(0.f, 0.5f, 0.0f), 0.f)));
	subArmLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Rotate>(Vector3(45.0f, 0.0f, 0.0f), 0.f)));

	std::unique_ptr<Animation>	legLeftAnim(new Animation());
	legLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Origin>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	legLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Translate>(Vector3(0.3f, -0.5f, 0.0f), 0.f)));
	legLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Scale>(Vector3(0.35f, 0.5f, 0.7f), 0.f)));
	legLeftAnim->pushAnimator(Animation::AnimatorPtr(new LerpAnimator<Anim::Rotate>(Vector3(145.0f, 0.0f, 0.0f), Vector3(215.f, 0.f, 0.f), 0.f, 1.f)));
	legLeftAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Rotate>(Vector3(215.0f, 0.0f, 0.0f), Vector3(145.f, 0.f, 0.f), 1.f, 1.f)));

	std::unique_ptr<Animation>	subLegLeftAnim(new Animation());
	subLegLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Origin>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	subLegLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Translate>(Vector3(0.0f, 0.5f, 0.0f), 0.f)));
	subLegLeftAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Rotate>(Vector3(0.0f, 0.0f, 0.0f), Vector3(-25.f, 0.f, 0.f), 0.f, 0.5f)));
	subLegLeftAnim->pushAnimator(Animation::AnimatorPtr(new CerpAnimator<Anim::Rotate>(Vector3(-25.0f, 0.0f, 0.0f), Vector3(0.f, 0.f, 0.f), 0.5f, 0.5f)));
	subLegLeftAnim->pushAnimator(Animation::AnimatorPtr(new SetAnimator<Anim::Rotate>(Vector3(0.0f, 0.0f, 0.0f), 1.f, 1.f)));

	Node::NodePtr trunk(new Node());
	trunk->setAnimation(std::move(trunkAnim));

	Node::NodePtr armLeft(new Node());
	armLeft->setAnimation(std::move(armLeftAnim));

	Node::NodePtr subArmLeft(new Node());
	subArmLeft->setAnimation(std::move(subArmLeftAnim));

	Node::NodePtr armRight(new Node());
	armRight->setAnimation(std::move(armRightAnim));

	Node::NodePtr legLeft(new Node());
	legLeft->setAnimation(std::move(legLeftAnim));

	Node::NodePtr subLegLeft(new Node());
	subLegLeft->setAnimation(std::move(subLegLeftAnim));

	armRight->addChild(subArmLeft);
	armLeft->addChild(std::move(subArmLeft));
	legLeft->addChild(std::move(subLegLeft));
	trunk->addChild(std::move(armLeft));
	trunk->addChild(std::move(armRight));
	trunk->addChild(std::move(legLeft));

	Shader shader("resources/default.frag" ,"resources/default.vert");

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_FRONT);
	//glFrontFace(GL_CCW);
	//glEnable(GL_LIGHTING);
	//glEnable(GL_FOG);
	//glDepthMask(GL_TRUE);
	//glDisable(GL_LIGHTING);
	//glDisable(GL_FOG);
	Matrix		m_view;
	Matrix		m_projection;

	m_view.translate(Vector3(0.f, 0.f, -3.f));
	shader.setParameter("ViewMatrix", m_view);
	m_projection.perspectiveProjection(60.f, 800.f / 600.f, 0.1f, 100.f);
	shader.setParameter("ProjectionMatrix", m_projection);

	glfwSetTime(0.f);
	float lastTime = 0.f;
	while (win.isOpen())
	{
		// Compute frametime
		float currentTime = glfwGetTime();
		float frameTime = (currentTime - lastTime);
		lastTime = currentTime;

		if (glfwGetKey(win.getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
			win.close();

		if (glfwGetKey(win.getWindow(), GLFW_KEY_R) == GLFW_PRESS)
			trunk->play();

		if (glfwGetKey(win.getWindow(), GLFW_KEY_E) == GLFW_PRESS)
			trunk->pause();

		if (glfwGetKey(win.getWindow(), GLFW_KEY_T) == GLFW_PRESS)
			trunk->stop();

		// Update
		trunk->update(frameTime);

		// Draw
		win.clear();

		trunk->draw(shader);

		win.display();
		win.pollEvents();
	}
	return (0);
}
