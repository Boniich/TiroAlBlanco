#pragma once

struct WinLossData {
	const char* title;
	int title_x;
	int title_y;
	const char* sub_title;
	int sub_title_x;
	int sub_title_y;
};

const WinLossData WIN = { "JUEGO TERMINADO" ,35,5, "Felicitaciones!Has completado el juego",25,6 };
const WinLossData LOSS = { "GAME OVER" ,35,5,"No pudiste superar el reto. Vuelve a intentarlo" ,20,6 };