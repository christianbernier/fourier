import { Constants } from "./Constants";
import type { LoadedPath } from "./LoadedPath";

export const getPathsFromLocalStorage = (): Array<LoadedPath> => {
  const currentLocalStoragePathsString = window.localStorage.getItem(Constants.LOCAL_STORAGE_PATHS_KEY);
	const paths =
    currentLocalStoragePathsString === null
    ? Constants.DEFAULT_PATHS
    : JSON.parse(currentLocalStoragePathsString);

	if (currentLocalStoragePathsString === null) {
		window.localStorage.setItem(Constants.LOCAL_STORAGE_PATHS_KEY, JSON.stringify(Constants.DEFAULT_PATHS))
	}

  return paths;
}

export const addPathToLocalStorage = (newPath: LoadedPath) => {
  const newLocalStoragePaths = [
    ...getPathsFromLocalStorage(),
    newPath,
  ]

  window.localStorage.setItem(Constants.LOCAL_STORAGE_PATHS_KEY, JSON.stringify(newLocalStoragePaths))
}

export const deletePathFromLocalStorage = (pathToDelete: LoadedPath) => {
  const newLocalStoragePaths = getPathsFromLocalStorage().filter(path => path.key !== pathToDelete.key)

  window.localStorage.setItem(Constants.LOCAL_STORAGE_PATHS_KEY, JSON.stringify(newLocalStoragePaths))
}
