#include <iostream>

#define GLM_FORCE_SWIZZLE
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

void Constructors() {
	std::cout << std::endl;

	glm::vec2 Point0(10.0f, 0.0f);
	glm::vec3 Point1(10.0f, 0.0f, 0.0f);
	glm::vec4 Point2(10.0f, 0.0f, 0.0f, 1.0f);
	glm::ivec2 Point3(10, 0);
	glm::bvec2 Point4(true, false);
	glm::dvec2 Point5(10.0, 0.0);
	glm::vec3 Point6(Point0, 0.0f);


	std::cout << "Point0: " << glm::to_string(Point0) << std::endl;
	std::cout << "Point1: " << glm::to_string(Point1) << std::endl;
	std::cout << "Point2: " << glm::to_string(Point2) << std::endl;
	std::cout << "Point3: " << glm::to_string(Point3) << std::endl;
	std::cout << "Point4: " << glm::to_string(Point4) << std::endl;
	std::cout << "Point5: " << glm::to_string(Point5) << std::endl;
	std::cout << "Point6: " << glm::to_string(Point6) << std::endl;
}

void Components() {
	std::cout << std::endl;

	glm::vec3 P(1, 2, 3);

	// Coordenadas de posição
	std::cout << "X: " << P.x;
	std::cout << " Y: " << P.y;
	std::cout << " Z: " << P.z;
	std::cout << std::endl;


	// Coordenadas de cores
	std::cout << "R: " << P.r;
	std::cout << " G: " << P.g;
	std::cout << " B: " << P.b;
	std::cout << std::endl;

	// Cordenadas de textura
	std::cout << "S: " << P.s;
	std::cout << " T: " << P.t;
	std::cout << " P: " << P.p;
	std::cout << std::endl;

	std::cout << "0: " << P[0];
	std::cout << " 1: " << P[1];
	std::cout << " 2: " << P[2];
}

void Swizzle() {
	std::cout << std::endl;

	glm::vec4 P{ 1, 2, 3, 4 };

	glm::vec3 Q = P.xxx;
	glm::vec3 R = P.xyx;
	glm::vec4 T = P.zyxw;
	glm::vec4 Y = P.xzzw;

	std::cout << glm::to_string(Q) << std::endl;
}

void Operations(){
	std::cout << std::endl;

	glm::vec3 P0(10.0f, 10.0f, 0.0f);
	glm::vec3 P1(20.0f, 20.0f, 0.0f);

	//Soma
	glm::vec3 R = P0 + P1;

	std::cout << glm::to_string(R) << std::endl;

	//Subtração
	glm::vec3 Q = P0 - P1;

	// Multiplicação
	glm::vec3 M = P0 * 10.0f;

	//Scala
	glm::vec3 S = P0 * 10.0f;

	std::cout << glm::to_string(S) << std::endl;

	//Magnitude
	float MA = glm::length(P0);

	std::cout << MA << std::endl;

	//Normalização
	glm::vec3 N = glm::normalize(P0);

	std::cout << "Normalizado:" << std::endl;
	std::cout << glm::to_string(N) << std::endl;

	//Produto escalar
	float D = glm::dot(P0, P1);

	std::cout << "Produto escalar:" << std::endl;
	std::cout << D << std::endl;

	// Distância
	float Dist = glm::distance(P0, P1);

	std::cout << "Distancia:" << std::endl;
	std::cout << Dist << std::endl;

	// Refração
	glm::vec3 I = glm::refract(P0, N, 0.5f);

	std::cout << "Refracao:" << std::endl;
	std::cout << glm::to_string(I) << std::endl;

	// Reflexão
	glm::vec3 Rf = glm::reflect(P0, N);

	std::cout << "Reflexao:" << std::endl;
	std::cout << glm::to_string(Rf) << std::endl;
}

int init() {
	Constructors();
	Components();
	Swizzle();
	Operations();
	return 0;
}