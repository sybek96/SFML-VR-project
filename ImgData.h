#pragma once

/// <summary>
/// Image data struct
/// </summary>
struct ImgData
{
	ImgData() :
		m_width(0),
		m_height(0),
		m_comp_count(0),
		m_img_data(nullptr)
	{
	}
	ImgData(unsigned char * imgData) :
		m_width(0),
		m_height(0),
		m_comp_count(0),
		m_img_data(m_img_data)
	{
	}

	int m_width;			// Width of texture
	int m_height;			// Height of texture
	int m_comp_count;		// Component of texture

	unsigned char* m_img_data;		// image data
};