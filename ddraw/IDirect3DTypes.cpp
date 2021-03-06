/**
* Copyright (C) 2018 Elisha Riedlinger
*
* This software is  provided 'as-is', without any express  or implied  warranty. In no event will the
* authors be held liable for any damages arising from the use of this software.
* Permission  is granted  to anyone  to use  this software  for  any  purpose,  including  commercial
* applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*   1. The origin of this software must not be misrepresented; you must not claim that you  wrote the
*      original  software. If you use this  software  in a product, an  acknowledgment in the product
*      documentation would be appreciated but is not required.
*   2. Altered source versions must  be plainly  marked as such, and  must not be  misrepresented  as
*      being the original software.
*   3. This notice may not be removed or altered from any source distribution.
*/

#include "ddraw.h"

void ConvertMaterial(D3DMATERIAL &Material, D3DMATERIAL7 &Material7)
{
	DWORD dwSize = (Material.dwSize > sizeof(D3DMATERIAL)) ? sizeof(D3DMATERIAL) : Material.dwSize;
	D3DMATERIAL tmpMaterial = { NULL };
	tmpMaterial.dwSize = dwSize;
	tmpMaterial.diffuse = Material7.diffuse;
	tmpMaterial.dcvDiffuse = Material7.dcvDiffuse;
	tmpMaterial.ambient = Material7.ambient;
	tmpMaterial.dcvAmbient = Material7.dcvAmbient;
	tmpMaterial.specular = Material7.specular;
	tmpMaterial.dcvSpecular = Material7.dcvSpecular;
	tmpMaterial.emissive = Material7.emissive;
	tmpMaterial.dcvEmissive = Material7.dcvEmissive;
	tmpMaterial.power = Material7.power;
	tmpMaterial.dvPower = Material7.dvPower;
	// Extra parameters
	//tmpMaterial.hTexture = 0;    /* Handle to texture map */
	//tmpMaterial.dwRampSize = 0;
	// Copy to variable
	CopyMemory(&Material, &tmpMaterial, dwSize);
}

void ConvertMaterial(D3DMATERIAL7 &Material7, D3DMATERIAL &Material)
{
	Material7.diffuse = Material7.diffuse;
	Material7.dcvDiffuse = Material7.dcvDiffuse;
	Material7.ambient = Material7.ambient;
	Material7.dcvAmbient = Material7.dcvAmbient;
	Material7.specular = Material7.specular;
	Material7.dcvSpecular = Material7.dcvSpecular;
	Material7.emissive = Material7.emissive;
	Material7.dcvEmissive = Material7.dcvEmissive;
	Material7.power = Material7.power;
	Material.dvPower = Material7.dvPower;
}

void ConvertViewport(D3DVIEWPORT &ViewPort, D3DVIEWPORT &ViewPort2)
{
	DWORD dwSize = (ViewPort.dwSize > sizeof(D3DVIEWPORT)) ? sizeof(D3DVIEWPORT) : ViewPort.dwSize;
	ZeroMemory(&ViewPort, dwSize);
	memcpy(&ViewPort, &ViewPort2, (dwSize > ViewPort2.dwSize) ? ViewPort2.dwSize : dwSize);
	ViewPort.dwSize = dwSize;
}

void ConvertViewport(D3DVIEWPORT2 &ViewPort, D3DVIEWPORT2 &ViewPort2)
{
	DWORD dwSize = (ViewPort.dwSize > sizeof(D3DVIEWPORT2)) ? sizeof(D3DVIEWPORT2) : ViewPort.dwSize;
	ZeroMemory(&ViewPort, dwSize);
	memcpy(&ViewPort, &ViewPort2, (dwSize > ViewPort2.dwSize) ? ViewPort2.dwSize : dwSize);
	ViewPort.dwSize = dwSize;
}

void ConvertViewport(D3DVIEWPORT &ViewPort, D3DVIEWPORT2 &ViewPort2)
{
	// Prepare varables
	DWORD dwSize = (ViewPort.dwSize > sizeof(D3DVIEWPORT)) ? sizeof(D3DVIEWPORT) : ViewPort.dwSize;
	D3DVIEWPORT tmpViewPort = { NULL };
	D3DVIEWPORT2 tmpViewPort2 = { NULL };
	CopyMemory(&tmpViewPort2, &ViewPort2, (sizeof(D3DVIEWPORT2) > ViewPort2.dwSize) ? ViewPort2.dwSize : sizeof(D3DVIEWPORT2));
	// Convert varables
	tmpViewPort.dwSize = dwSize;
	tmpViewPort.dwX = ViewPort2.dwX;
	tmpViewPort.dwY = ViewPort2.dwY;
	tmpViewPort.dwWidth = ViewPort2.dwWidth;
	tmpViewPort.dwHeight = ViewPort2.dwHeight;
	tmpViewPort.dvMinZ = ViewPort2.dvMinZ;
	tmpViewPort.dvMaxZ = ViewPort2.dvMaxZ;
	// Extra parameters
	//tmpViewPort.dvScaleX = 0;        /* Scale homogeneous to screen */
	//tmpViewPort.dvScaleY = 0;        /* Scale homogeneous to screen */
	//tmpViewPort.dvMaxX = 0;          /* Min/max homogeneous x coord */
	//tmpViewPort.dvMaxY = 0;          /* Min/max homogeneous y coord */
	// Copy to variable
	CopyMemory(&ViewPort, &tmpViewPort, dwSize);
}

void ConvertViewport(D3DVIEWPORT2 &ViewPort2, D3DVIEWPORT &ViewPort)
{
	// Prepare varables
	DWORD dwSize = (ViewPort2.dwSize > sizeof(D3DVIEWPORT2)) ? sizeof(D3DVIEWPORT2) : ViewPort2.dwSize;
	D3DVIEWPORT2 tmpViewPort2 = { NULL };
	D3DVIEWPORT tmpViewPort = { NULL };
	CopyMemory(&tmpViewPort, &ViewPort, (sizeof(D3DVIEWPORT) > ViewPort.dwSize) ? ViewPort.dwSize : sizeof(D3DVIEWPORT));
	// Convert varables
	tmpViewPort2.dwSize = dwSize;
	tmpViewPort2.dwX = ViewPort.dwX;
	tmpViewPort2.dwY = ViewPort.dwY;
	tmpViewPort2.dwWidth = ViewPort.dwWidth;
	tmpViewPort2.dwHeight = ViewPort.dwHeight;
	tmpViewPort2.dvMinZ = ViewPort.dvMinZ;
	tmpViewPort2.dvMaxZ = ViewPort.dvMaxZ;
	// Extra parameters
	//tmpViewPort2.dvClipX = 0;        /* Top left of clip volume */
	//tmpViewPort2.dvClipY = 0;
	//tmpViewPort2.dvClipWidth = 0;    /* Clip Volume Dimensions */
	//tmpViewPort2.dvClipHeight = 0;
	// Copy to variable
	CopyMemory(&ViewPort2, &tmpViewPort2, dwSize);
}

void ConvertViewport(D3DVIEWPORT &ViewPort, D3DVIEWPORT7 &ViewPort7)
{
	DWORD dwSize = (ViewPort.dwSize > sizeof(D3DVIEWPORT)) ? sizeof(D3DVIEWPORT) : ViewPort.dwSize;
	D3DVIEWPORT tmpViewPort = { NULL };
	tmpViewPort.dwSize = dwSize;
	tmpViewPort.dwX = ViewPort7.dwX;
	tmpViewPort.dwY = ViewPort7.dwY;
	tmpViewPort.dwWidth = ViewPort7.dwWidth;
	tmpViewPort.dwHeight = ViewPort7.dwHeight;
	tmpViewPort.dvMinZ = ViewPort7.dvMinZ;
	tmpViewPort.dvMaxZ = ViewPort7.dvMaxZ;
	// Extra parameters
	//tmpViewPort.dvScaleX = 0;        /* Scale homogeneous to screen */
	//tmpViewPort.dvScaleY = 0;        /* Scale homogeneous to screen */
	//tmpViewPort.dvMaxX = 0;          /* Min/max homogeneous x coord */
	//tmpViewPort.dvMaxY = 0;          /* Min/max homogeneous y coord */
	// Copy to variable
	CopyMemory(&ViewPort, &tmpViewPort, dwSize);
}

void ConvertViewport(D3DVIEWPORT2 &ViewPort2, D3DVIEWPORT7 &ViewPort7)
{
	DWORD dwSize = (ViewPort2.dwSize > sizeof(D3DVIEWPORT2)) ? sizeof(D3DVIEWPORT2) : ViewPort2.dwSize;
	D3DVIEWPORT2 tmpViewPort2 = { NULL };
	tmpViewPort2.dwSize = dwSize;
	tmpViewPort2.dwX = ViewPort7.dwX;
	tmpViewPort2.dwY = ViewPort7.dwY;
	tmpViewPort2.dwWidth = ViewPort7.dwWidth;
	tmpViewPort2.dwHeight = ViewPort7.dwHeight;
	tmpViewPort2.dvMinZ = ViewPort7.dvMinZ;
	tmpViewPort2.dvMaxZ = ViewPort7.dvMaxZ;
	// Extra parameters
	//tmpViewPort2.dvClipX = 0;        /* Top left of clip volume */
	//tmpViewPort2.dvClipY = 0;
	//tmpViewPort2.dvClipWidth = 0;    /* Clip Volume Dimensions */
	//tmpViewPort2.dvClipHeight = 0;
	// Copy to variable
	CopyMemory(&ViewPort2, &tmpViewPort2, dwSize);
}

void ConvertViewport(D3DVIEWPORT7 &ViewPort7, D3DVIEWPORT &ViewPort)
{
	ViewPort7.dwX = ViewPort.dwX;
	ViewPort7.dwY = ViewPort.dwY;
	ViewPort7.dwWidth = ViewPort.dwWidth;
	ViewPort7.dwHeight = ViewPort.dwHeight;
	ViewPort7.dvMinZ = ViewPort.dvMinZ;
	ViewPort7.dvMaxZ = ViewPort.dvMaxZ;
}

void ConvertViewport(D3DVIEWPORT7 &ViewPort7, D3DVIEWPORT2 &ViewPort2)
{
	ViewPort7.dwX = ViewPort2.dwX;
	ViewPort7.dwY = ViewPort2.dwY;
	ViewPort7.dwWidth = ViewPort2.dwWidth;
	ViewPort7.dwHeight = ViewPort2.dwHeight;
	ViewPort7.dvMinZ = ViewPort2.dvMinZ;
	ViewPort7.dvMaxZ = ViewPort2.dvMaxZ;
}

void ConvertViewport(D3DVIEWPORT7 &ViewPort, D3DVIEWPORT7 &ViewPort7)
{
	CopyMemory(&ViewPort, &ViewPort7, sizeof(D3DVIEWPORT7));
}

void ConvertDeviceDesc(D3DDEVICEDESC &Desc, D3DDEVICEDESC7 &Desc7)
{
	// Prepare varables
	DWORD dwSize = (Desc.dwSize > sizeof(D3DDEVICEDESC)) ? sizeof(D3DDEVICEDESC) : Desc.dwSize;
	D3DDEVICEDESC tmpDesc = { NULL };
	// Convert varables
	tmpDesc.dwDevCaps = dwSize;
	CopyMemory(&tmpDesc.dpcLineCaps, &Desc7.dpcLineCaps, sizeof(D3DPRIMCAPS));
	CopyMemory(&tmpDesc.dpcTriCaps, &Desc7.dpcTriCaps, sizeof(D3DPRIMCAPS));
	tmpDesc.dwDeviceRenderBitDepth = Desc7.dwDeviceRenderBitDepth;
	tmpDesc.dwDeviceZBufferBitDepth = Desc7.dwDeviceZBufferBitDepth;
	tmpDesc.dwMaxTextureRepeat = Desc7.dwMaxTextureRepeat;
	tmpDesc.dwFlags = (D3DDD_DEVCAPS | D3DDD_LINECAPS | D3DDD_TRICAPS | D3DDD_DEVICERENDERBITDEPTH | D3DDD_DEVICEZBUFFERBITDEPTH);
	// Extra parameters
	//tmpDesc.dcmColorModel = 0;                 /* Color model of device */
	//tmpDesc.dtcTransformCaps.dwCaps = 0;       /* Capabilities of transform */
	tmpDesc.dtcTransformCaps.dwSize = sizeof(D3DTRANSFORMCAPS);
	//tmpDesc.bClipping = 0;                     /* Device can do 3D clipping */
	//tmpDesc.dlcLightingCaps.dwCaps = 0;        /* Capabilities of lighting */
	//tmpDesc.dlcLightingCaps.dwLightingModel = 0;
	//tmpDesc.dlcLightingCaps.dwNumLights = 0;
	tmpDesc.dlcLightingCaps.dwSize = sizeof(D3DLIGHTINGCAPS);
	//tmpDesc.dwMaxBufferSize = 0;               /* Maximum execute buffer size */
	//tmpDesc.dwMaxVertexCount = 0;              /* Maximum vertex count */
	/* DIRECT3D_VERSION >= 0x0500 */
	tmpDesc.dwMinTextureWidth = Desc7.dwMinTextureWidth;
	tmpDesc.dwMinTextureHeight = Desc7.dwMinTextureHeight;
	tmpDesc.dwMaxTextureWidth = Desc7.dwMaxTextureWidth;
	tmpDesc.dwMaxTextureHeight = Desc7.dwMaxTextureHeight;
	// Extra parameters
	//tmpDesc.dwMinStippleWidth = 0;
	//tmpDesc.dwMaxStippleWidth = 0;
	//tmpDesc.dwMinStippleHeight = 0;
	//tmpDesc.dwMaxStippleHeight = 0;
	/* DIRECT3D_VERSION >= 0x0600 */
	tmpDesc.dwMaxTextureAspectRatio = Desc7.dwMaxTextureAspectRatio;
	tmpDesc.dwMaxAnisotropy = Desc7.dwMaxAnisotropy;
	tmpDesc.dvGuardBandLeft = Desc7.dvGuardBandLeft;
	tmpDesc.dvGuardBandTop = Desc7.dvGuardBandTop;
	tmpDesc.dvGuardBandRight = Desc7.dvGuardBandRight;
	tmpDesc.dvGuardBandBottom = Desc7.dvGuardBandBottom;
	tmpDesc.dvExtentsAdjust = Desc7.dvExtentsAdjust;
	tmpDesc.dwStencilCaps = Desc7.dwStencilCaps;
	tmpDesc.dwFVFCaps = Desc7.dwFVFCaps;
	tmpDesc.dwTextureOpCaps = Desc7.dwTextureOpCaps;
	tmpDesc.wMaxTextureBlendStages = Desc7.wMaxTextureBlendStages;
	tmpDesc.wMaxSimultaneousTextures = Desc7.wMaxSimultaneousTextures;
	// Copy to variable
	CopyMemory(&Desc, &tmpDesc, dwSize);
}

void ConvertDeviceDesc(D3DDEVICEDESC7 &Desc7, D3DCAPS9 &Caps9)
{
	// General settings
	Desc7.dwMinTextureWidth = (Caps9.MaxTextureWidth) ? 1 : 0;
	Desc7.dwMinTextureHeight = (Caps9.MaxTextureHeight) ? 1 : 0;
	Desc7.dwMaxTextureWidth = Caps9.MaxTextureWidth;
	Desc7.dwMaxTextureHeight = Caps9.MaxTextureHeight;
	Desc7.dwMaxTextureRepeat = Caps9.MaxTextureRepeat;
	Desc7.dwMaxTextureAspectRatio = Caps9.MaxTextureAspectRatio;
	Desc7.dwMaxAnisotropy = Caps9.MaxAnisotropy;
	Desc7.dvGuardBandLeft = Caps9.GuardBandLeft;
	Desc7.dvGuardBandTop = Caps9.GuardBandTop;
	Desc7.dvGuardBandRight = Caps9.GuardBandRight;
	Desc7.dvGuardBandBottom = Caps9.GuardBandBottom;
	Desc7.dvExtentsAdjust = Caps9.ExtentsAdjust;
	Desc7.wMaxTextureBlendStages = (WORD)((Caps9.MaxTextureBlendStages > 0xFFFF) ? 0xFFFF : Caps9.MaxTextureBlendStages);
	Desc7.wMaxSimultaneousTextures = (WORD)((Caps9.MaxSimultaneousTextures > 0xFFFF) ? 0xFFFF : Caps9.MaxSimultaneousTextures);
	Desc7.dwMaxActiveLights = Caps9.MaxActiveLights;
	Desc7.dvMaxVertexW = Caps9.MaxVertexW;
	Desc7.wMaxUserClipPlanes = (WORD)((Caps9.MaxUserClipPlanes > 0xFFFF) ? 0xFFFF : Caps9.MaxUserClipPlanes);
	Desc7.wMaxVertexBlendMatrices = (WORD)((Caps9.MaxVertexBlendMatrices > 0xFFFF) ? 0xFFFF : Caps9.MaxVertexBlendMatrices);

	// Caps
	Desc7.dwDevCaps = (Caps9.DevCaps & 0x2FFFF);
	Desc7.dwStencilCaps = (Caps9.StencilCaps & 0xFF);
	Desc7.dwFVFCaps = (Caps9.FVFCaps & 0x8FFFF);
	Desc7.dwTextureOpCaps = (Caps9.TextureOpCaps & 0xFFFFFF);
	Desc7.dwVertexProcessingCaps = (Caps9.VertexProcessingCaps & 0x3F);

	// Line Caps
	Desc7.dpcLineCaps.dwSize = sizeof(D3DPRIMCAPS);
	Desc7.dpcLineCaps.dwMiscCaps = (Caps9.PrimitiveMiscCaps & 0x8F);
	Desc7.dpcLineCaps.dwRasterCaps = (Caps9.RasterCaps & 0x3FFFFF);
	Desc7.dpcLineCaps.dwZCmpCaps = (Caps9.ZCmpCaps & 0xFF);
	Desc7.dpcLineCaps.dwSrcBlendCaps = (Caps9.SrcBlendCaps & 0x1FFF);
	Desc7.dpcLineCaps.dwDestBlendCaps = (Caps9.DestBlendCaps & 0x1FFF);
	Desc7.dpcLineCaps.dwAlphaCmpCaps = (Caps9.AlphaCmpCaps & 0xFF);
	Desc7.dpcLineCaps.dwShadeCaps = (Caps9.ShadeCaps & 0x1FFFFF);
	Desc7.dpcLineCaps.dwTextureCaps = (Caps9.TextureCaps & 0x1FFF);
	Desc7.dpcLineCaps.dwTextureFilterCaps = (Caps9.TextureFilterCaps & 0x1F373F);
	Desc7.dpcLineCaps.dwTextureBlendCaps = (D3DPTBLENDCAPS_DECAL | D3DPTBLENDCAPS_MODULATE | D3DPTBLENDCAPS_DECALALPHA | D3DPTBLENDCAPS_MODULATEALPHA | D3DPTBLENDCAPS_COPY | D3DPTBLENDCAPS_ADD);
	Desc7.dpcLineCaps.dwTextureAddressCaps = (Caps9.TextureAddressCaps & 0x1F);

	// Tri Caps same as Line Caps
	memcpy(&Desc7.dpcTriCaps, &Desc7.dpcLineCaps, sizeof(D3DPRIMCAPS));

	// Specific settings
	if (Caps9.DeviceType == D3DDEVTYPE_REF)
	{
		Desc7.deviceGUID = IID_IDirect3DRGBDevice;
		Desc7.dpcLineCaps.dwStippleWidth = 4;
		Desc7.dpcLineCaps.dwStippleHeight = 4;
		Desc7.dwDeviceRenderBitDepth = 3840;
		Desc7.dwDeviceZBufferBitDepth = 1024;
	}
	else if (Caps9.DeviceType == D3DDEVTYPE_HAL)
	{
		Desc7.deviceGUID = IID_IDirect3DHALDevice;
		Desc7.dwDevCaps |= D3DDEVCAPS_HWRASTERIZATION;
		Desc7.dpcLineCaps.dwStippleWidth = 0;
		Desc7.dpcLineCaps.dwStippleHeight = 0;
		Desc7.dwDeviceRenderBitDepth = 3328;
		Desc7.dwDeviceZBufferBitDepth = 1536;
	}
	else if (Caps9.DeviceType == D3DDEVTYPE_HAL + 0x10)
	{
		Desc7.deviceGUID = IID_IDirect3DTnLHalDevice;
		Desc7.dwDevCaps |= D3DDEVCAPS_HWRASTERIZATION | D3DDEVCAPS_HWTRANSFORMANDLIGHT;
		Desc7.dpcLineCaps.dwStippleWidth = 0;
		Desc7.dpcLineCaps.dwStippleHeight = 0;
		Desc7.dwDeviceRenderBitDepth = 3328;
		Desc7.dwDeviceZBufferBitDepth = 1536;
	}

	// Reserved
	Desc7.dwReserved1 = 0;
	Desc7.dwReserved2 = 0;
	Desc7.dwReserved3 = 0;
	Desc7.dwReserved4 = 0;
}
