#include "Graphics.h"

Graphics::Graphics()
{

}

bool Graphics::initGlad(GLADloadproc gladProc)
{
	return gladLoadGLLoader(gladProc);
}

