import { PiPath, SquarePath } from "./paths";

export const Constants = {
  CANVAS_WIDTH: 500,
  CANVAS_HEIGHT: 500,
  CANVAS_STROKE_SIZE: 2,
  CANVAS_BORDER_WIDTH: 2,
  COLOR_LIGHT: '#FFFFFA',
  COLOR_DARK: '#151515',
  COLOR_PRIMARY: '#71A9F7',
  LOCAL_STORAGE_PATHS_KEY: 'paths',
  DEFAULT_PATHS: [
    PiPath,
    SquarePath,
  ]
} as const;
