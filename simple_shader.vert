#version 450

layout(location = 0) in vec2 position;

// gl_VertexIndex contains the index of the current vertex each time the main  funktion is run

void main() {
	gl_Position = vec4(position, 0.0, 1.0);
}