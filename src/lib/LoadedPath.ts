import type { CanvasPoint } from "./CanvasPoint";
import type { Epicycle } from "./Epicycle";

export type LoadedPath = {
  key: string;
  name: string;
  inputPoints: Array<CanvasPoint>;
  epicycles: Array<Epicycle>;
  isDefaultPath: boolean;
}
