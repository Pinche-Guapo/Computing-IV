for (int x = 0; x<200; x++) {
	for (int y = 0; y< 200; y++) {
		p = image.getPixel(x, y);
		p.r = 255 - p.r;
		p.g = 255 - p.g;
		p.b = 255 - p.b;
		image.setPixel(x, y, p);
	}
}

