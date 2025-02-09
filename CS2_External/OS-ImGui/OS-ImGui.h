#pragma once
#include "OS-ImGui_External.h"

namespace OSImGui
{
#ifdef _CONSOLE
	class OSImGui : public OSImGui_External, public Singleton<OSImGui>
#else
	class OSImGui : public OSImGui_Internal, public Singleton<OSImGui>
#endif
	{
	public:
		bool LoadTextureFromFile(const char* filename, ID3D11ShaderResourceView** out_srv, int* out_width, int* out_height);
		bool LoadTextureFromMemory(unsigned char* Memory, UINT size, ID3D11ShaderResourceView** out_srv, int* out_width, int* out_height);
		void ShowRawImage(unsigned char* image, int width, int height);

		void Text(std::string Text, Vec2 Pos, ImColor Color, float FontSize = 15, bool KeepCenter = false);
		void MyText(std::string Text, bool isCenter);
		void StrokeText(std::string Text, Vec2 Pos, ImColor Color, float FontSize = 15, bool KeepCenter = false);
		void Rectangle(Vec2 Pos, Vec2 Size, ImColor Color, float Thickness, float Rounding = 0);
		void RectangleFilled(Vec2 Pos, Vec2 Size, ImColor Color, float Rounding = 0, int Nums = 15);
		void RectangleFilledGraident(Vec2 Pos, Vec2 Size, ImColor BgColor, ImColor TopColor, ImColor BotColor, float Rounding, int Nums = 15);
		void Line(Vec2 From, Vec2 To, ImColor Color, float Thickness);
		void LineGlow(Vec2 From, Vec2 To, ImColor Color, float Thickness);
		void CircleGradient(const Vec2 center, float radius, ImColor col_in, ImColor col_out);

		void Circle(Vec2 Center, float Radius, ImColor Color, float Thickness, int Num = 50);
		void CircleFilled(Vec2 Center, float Radius, ImColor Color, int Num = 50);
		void ConnectPoints(std::vector<Vec2> Points, ImColor Color, float Thickness);
		void Arc(ImVec2 Center, float Radius, ImColor Color, float Thickness, float Aangle_begin, float Angle_end, float Nums = 15);

		void ShadowRectFilled(Vec2 Pos, Vec2 Size, ImColor RectColor, ImColor ShadowColor, float ShadowThickness, Vec2 ShadowOffset, float Rounding = 0);
		void ShadowCircle(Vec2 Pos, float Radius, ImColor CircleColor, ImColor ShadowColor, float ShadowThickness, Vec2 ShadowOffset, int Num = 30);

		bool Slider(const char* label, ImGuiDataType data_type, void* p_data, float p_min, float p_max, const char* format, ImU32 Theme, ImGuiSliderFlags flags);
		void MyProgressBar(float fraction, const ImVec2& Size, const char* overlay, ImVec4 Color);
	};
}

inline OSImGui::OSImGui& Gui = OSImGui::OSImGui::get();