#pragma once

#define ARGB(a, r, g, b) 0 | a << 24 | r << 16 | g << 8 | b

float Rainbow() {
	static float x = 0, y = 0;
	static float r = 0, g = 0, b = 0;
	if (y >= 0.0f && y < 255.0f) {
		r = 255.0f;
		g = 0.0f;
		b = x;
	} else if (y >= 255.0f && y < 510.0f) {
		r = 255.0f - x;
		g = 0.0f;
		b = 255.0f;
	} else if (y >= 510.0f && y < 765.0f) {
		r = 0.0f;
		g = x;
		b = 255.0f;
	} else if (y >= 765.0f && y < 1020.0f) {
		r = 0.0f;
		g = 255.0f;
		b = 255.0f - x;
	} else if (y >= 1020.0f && y < 1275.0f) {
		r = x;
		g = 255.0f;
		b = 0.0f;
	} else if (y >= 1275.0f && y < 1530.0f) {
		r = 255.0f;
		g = 255.0f - x;
		b = 0.0f;
	}
	x+= 0.25f; 
	if (x >= 255.0f)
		x = 0.0f;
	y+= 0.25f;
	if (y > 1530.0f)
		y = 0.0f;
	return ARGB(255, (int)r, (int)g, (int)b);
}

bool isOutsideScreen(ImVec2 pos, ImVec2 screen) {
    if (pos.y < 0) {
        return true;
    }
    if (pos.x > screen.x) {
        return true;
    }
    if (pos.y > screen.y) {
        return true;
    }
    return pos.x < 0;
}

ImVec2 pushToScreenBorder(ImVec2 Pos, ImVec2 screen, int offset) {
    int x = (int) Pos.x;
    int y = (int) Pos.y;
    if (Pos.y < 0) {
        // top
        y = -offset;
    }
    if (Pos.x > screen.x) {
        // right
        x = (int) screen.x + offset;
    }
    if (Pos.y > screen.y) {
        // bottom
        y = (int) screen.y + offset;
    }
    if (Pos.x < 0) {
        // left
        x = -offset;
    }
    return ImVec2(x, y);
}


	void drawText(const char *text, float X, float Y, float size, long color) {
		ImGui::GetBackgroundDrawList()->AddText(NULL, size, ImVec2(X, Y), color, text);
	}
	
	void drawLine(float startX, float startY, float stopX, float stopY, float thicc, long color) {
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(startX, startY), ImVec2(stopX, stopY), color, thicc);
	}
	
	void drawBorder(float X, float Y, float width, float height, float thicc, long color) {
		ImGui::GetBackgroundDrawList()->AddRect(ImVec2(X, Y), ImVec2(X + width, Y + height), color, thicc);
	}
	
	void drawBox(float X, float Y, float width, float height, float thicc, long color) {
		ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(X, Y), ImVec2(X + width, Y + height), color, thicc);
	}
	
	void drawCornerBox(int x, int y, int w, int h, float thickness, long color) {
		int iw = w / 4;
		int ih = h / 4;
		
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(x, y), ImVec2(x + iw, y), color, thickness);
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(x, y), ImVec2(x, y + ih), color, thickness);
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(x + w - 1, y), ImVec2(x + w - 1, y + ih), color, thickness);
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(x, y + h), ImVec2(x + iw, y + h), color, thickness);
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(x + w - iw, y + h), ImVec2(x + w, y + h), color, thickness);
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(x, y + h - ih), ImVec2(x, y + h), color, thickness);
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(x + w - 1, y + h - ih), ImVec2(x + w - 1, y + h), color, thickness);
	
    }
