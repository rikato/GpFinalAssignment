#include "VertexArray.h"
#include "Renderer.h";
#include "VertexBufferLayout.h"

VertexArray::VertexArray()
{
	GLCall(glGenVertexArrays(1, &rendererId));
}

VertexArray::~VertexArray()
{
	GLCall(glDeleteVertexArrays(1, &rendererId))
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
	// Bind the vertex array.
	Bind();

	// Then bind the vertex buffer.
	vb.Bind();

	// Now setup the layout for the buffer.
	const auto& elements = layout.GetElements();
	unsigned int offset = 0;

	for (unsigned int i = 0; i < elements.size(); i++) 
	{
		const auto& element = elements[i];

		GLCall(glEnableVertexAttribArray(i));
		GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*) offset));

		offset += element.count * VertextBufferElement::GetSizeOfType(element.type);
	}
}

void VertexArray::Bind() const
{
	GLCall(glBindVertexArray(rendererId));
}

void VertexArray::UnBind() const
{
	GLCall(glBindVertexArray(0));
}